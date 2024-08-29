#pragma once

#include <cstdint>
#include <cstring>
#include <iterator>
#include <string_view>
#include <vector>

#include "serilite/for_each_internal.h"

namespace serilite {

using LengthType = uint16_t;
constexpr size_t LengthSize = sizeof(LengthType);

namespace details {

// Check if T has an iterator and a value_type member type.
template <typename T, typename = void>
struct has_iter_value : std::false_type {};

template <typename T>
struct has_iter_value<
    T, std::void_t<typename T::iterator, typename T::const_iterator,
                   typename T::value_type>> : std::true_type {};

// Alias for has_iter_value<T>::value.
template <typename T>
constexpr bool has_iter_value_v = has_iter_value<T>::value;

// Check if T is iterable.
template <typename T, typename = void>
struct is_iterable : std::false_type {};

template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()) ==
                                           std::end(std::declval<T>()))>>
    : std::bool_constant<has_iter_value_v<T>> {};

// Alias for is_iterable<T>::value.
template <typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;

// Check if T can be memcpy constructed from an iterator range.
template <typename T, typename = void>
struct is_memcpy_constructible : std::false_type {};

template <typename T>
struct is_memcpy_constructible<
    T, std::enable_if_t<is_iterable_v<T> &&
                        std::is_trivially_copyable_v<typename T::value_type>>>
    : std::is_same<typename std::iterator_traits<
                       typename T::iterator>::iterator_category,
                   std::random_access_iterator_tag> {};

// Alias for is_memcpy_constructible<T>::value.
template <typename T>
constexpr bool is_memcpy_constructible_v = is_memcpy_constructible<T>::value;

// A type that can be used as a placeholder for any type.
struct AnyType {
    template <typename T>
    operator T() const {};
};

// Count the number of members of a aggregate type T.
template <typename T, typename... Args>
struct MemberCount {
    constexpr static size_t _impl(int*) { return sizeof...(Args) - 1; }

    template <typename U = T, typename = std::void_t<decltype(U{Args{}...})>>
    constexpr static size_t _impl(std::nullptr_t) {
        return MemberCount<T, Args..., AnyType>::value;
    }
    constexpr static size_t value = _impl(nullptr);
};

// Alias for MemberCount<T>::value.
template <typename T>
constexpr size_t member_count_v = MemberCount<T>::value;

template <typename... Args>
constexpr size_t member_count_v<std::tuple<Args...>> = sizeof...(Args);

template <typename... Args>
constexpr size_t member_count_v<std::pair<Args...>> = 2;

template <auto N, typename T, typename ExecFunc>
void foreach_over_elements(T& value, ExecFunc&& func) {
    foreach_over_elements_impl(value, std::forward<ExecFunc>(func),
                               constant_size_t<N>{});
}

template <typename T,
          typename = std::void_t<decltype(std::declval<T>().data()),
                                 decltype(std::declval<T>().size())>>
std::string_view get_serialized_data(const T& value) {
    return {reinterpret_cast<const char*>(value.data()), value.size()};
}

}  // namespace details

struct SeriData {
    using bytes_vector = std::vector<std::byte>;
    using ele_type = std::byte;

    SeriData(size_t size = 0) : data_(size) {}

    const bytes_vector& as_vector() const { return data_; }

    const std::string_view as_string() const {
        return {reinterpret_cast<const char*>(data_.data()), data_.size()};
    }

    const auto* data() const { return as_string().data(); }

    size_t size() const { return data_.size(); }

    bytes_vector data_;
};

#define INSERT_LENGTH_INTO_RESULT(result, value)                    \
    do {                                                            \
        auto length_data = static_cast<LengthType>(value);          \
        std::memcpy(result.data_.data(), &length_data, LengthSize); \
    } while (0)

template <typename T,
          std::enable_if_t<std::is_trivially_copyable_v<T>, int> = 0>
SeriData serialize(const T& value) {
    size_t size = sizeof(T);
    SeriData result(size);
    std::memcpy(result.data_.data(), &value, size);
    return result;
}

template <typename T,
          std::enable_if_t<!std::is_trivially_copyable_v<T> &&
                               details::is_memcpy_constructible_v<T>,
                           int> = 0>
SeriData serialize(const T& value) {
    using value_type = typename T::value_type;
    size_t element_count = value.size();
    size_t source_size = element_count * sizeof(value_type);

    SeriData result(source_size + LengthSize);
    INSERT_LENGTH_INTO_RESULT(result, element_count);

    const value_type* source = &(*std::begin(value));
    std::memcpy(result.data_.data() + LengthSize, source, source_size);
    return result;
}

template <typename T,
          std::enable_if_t<!std::is_trivially_copyable_v<T> &&
                               !details::is_memcpy_constructible_v<T> &&
                               details::is_iterable_v<T>,
                           int> = 0>
SeriData serialize(const T& value) {
    using value_type = typename T::value_type;

    size_t element_count = std::size(value);
    size_t source_size = 0;
    std::vector<SeriData> temp(element_count);
    for (const value_type& element : value) {
        auto element_data = serialize(element);
        temp.emplace_back(std::move(element_data));
        source_size += element_data.size();
    }
    SeriData result(LengthSize + source_size);
    INSERT_LENGTH_INTO_RESULT(result, element_count);
    size_t offset = LengthSize;
    for (const auto& element_data : temp) {
        std::memcpy(result.data_.data() + offset, element_data.data(),
                    element_data.data_.size());
        offset += element_data.data_.size();
    }

    return result;
}

template <typename T, std::enable_if_t<!std::is_trivially_copyable_v<T> &&
                                           std::is_aggregate_v<T>,
                                       int> = 0>
SeriData serialize(const T& value) {
    constexpr auto member_count = details::member_count_v<T>;
    std::vector<SeriData> temp(member_count);
    size_t source_size = 0;
    details::foreach_over_elements<member_count>(
        value, [&temp, &source_size](const auto& element) {
            auto element_data = serialize(element);
            source_size += element_data.data_.size();
            temp.emplace_back(std::move(element_data));
        });
    SeriData result(source_size);

    size_t offset = 0;
    for (const auto& element_data : temp) {
        std::memcpy(result.data_.data() + offset, element_data.data(),
                    element_data.data_.size());
        offset += element_data.data_.size();
    }
    return result;
}

template <typename T, typename U,
          std::enable_if_t<std::is_trivially_copyable_v<T>, int> = 0>
bool deserialize(const U& serialized, T& value,
                 std::string_view* remain = nullptr) {
    auto view = details::get_serialized_data(serialized);
    size_t size = sizeof(T);
    if (view.size() < size) return false;
    std::memcpy(&value, view.data(), size);
    if (remain) *remain = view.substr(size);
    return true;
}

template <typename T, typename U,
          std::enable_if_t<!std::is_trivially_copyable_v<T> &&
                               details::is_memcpy_constructible_v<T>,
                           int> = 0>
bool deserialize(const U& serialized, T& value,
                 std::string_view* remain = nullptr) {
    auto view = details::get_serialized_data(serialized);
    using value_type = typename T::value_type;
    if (view.size() < LengthSize) return false;
    LengthType element_count = 0;
    std::memcpy(&element_count, view.data(), LengthSize);
    size_t source_size = element_count * sizeof(value_type);
    if (view.size() < LengthSize + source_size) return false;
    const value_type* source =
        reinterpret_cast<const value_type*>(view.data() + LengthSize);
    value = T{source, source + element_count};
    if (remain) *remain = view.substr(LengthSize + source_size);
    return true;
}

template <typename T, typename U,
          std::enable_if_t<!std::is_trivially_copyable_v<T> &&
                               !details::is_memcpy_constructible_v<T> &&
                               details::is_iterable_v<T>,
                           int> = 0>
bool deserialize(const U& serialized, T& value,
                 std::string_view* remain = nullptr) {
    auto& view = details::get_serialized_data(serialized);
    using value_type = typename T::value_type;
    if (view.size() < LengthSize) return false;
    LengthType element_count = 0;
    std::memcpy(&element_count, view.data(), LengthSize);
    if (view.size() < LengthSize + element_count * sizeof(value_type))
        return false;
    auto insert_iter = std::inserter(value, std::end(value));
    auto ele_view = view.substr(LengthSize);
    for (size_t i = 0; i < element_count; ++i) {
        value_type element;
        if (!deserialize(ele_view, element, &ele_view)) return false;
        *insert_iter++ = std::move(element);
    }
    if (remain) *remain = ele_view;
    return true;
}
template <
    typename T, typename U,
    std::enable_if_t<!std::is_trivially_copyable_v<T> && std::is_aggregate_v<T>,
                     int> = 0>
bool deserialize(const U& serialized, T& value,
                 std::string_view* remain = nullptr) {
    constexpr auto member_count = details::member_count_v<T>;
    auto view = details::get_serialized_data(serialized);
    bool success = true;
    details::foreach_over_elements<member_count>(
        value, [&view, &success](auto& element) {
            if (!success) return;
            success &= deserialize(view, element, &view);
        });
    if (remain) *remain = view;
    return success;
}

#undef INSERT_LENGTH_INTO_RESULT

}  // namespace serilite