#pragma once
#include <type_traits>
#include <utility>
// clang-format off

#define SERILITE_MACRO_EXPAND(...) __VA_ARGS__

#define SERILITE_DECLARE_ONE(x) _BINDS_VAR_##x

#define SERILITE_VAR_BIND_IMPL_1 SERILITE_DECLARE_ONE(1)
#define SERILITE_VAR_BIND_IMPL_2 SERILITE_VAR_BIND_IMPL_1,SERILITE_DECLARE_ONE(2)
#define SERILITE_VAR_BIND_IMPL_3 SERILITE_VAR_BIND_IMPL_2,SERILITE_DECLARE_ONE(3)
#define SERILITE_VAR_BIND_IMPL_4 SERILITE_VAR_BIND_IMPL_3,SERILITE_DECLARE_ONE(4)
#define SERILITE_VAR_BIND_IMPL_5 SERILITE_VAR_BIND_IMPL_4,SERILITE_DECLARE_ONE(5)
#define SERILITE_VAR_BIND_IMPL_6 SERILITE_VAR_BIND_IMPL_5,SERILITE_DECLARE_ONE(6)
#define SERILITE_VAR_BIND_IMPL_7 SERILITE_VAR_BIND_IMPL_6,SERILITE_DECLARE_ONE(7)
#define SERILITE_VAR_BIND_IMPL_8 SERILITE_VAR_BIND_IMPL_7,SERILITE_DECLARE_ONE(8)
#define SERILITE_VAR_BIND_IMPL_9 SERILITE_VAR_BIND_IMPL_8,SERILITE_DECLARE_ONE(9)
#define SERILITE_VAR_BIND_IMPL_10 SERILITE_VAR_BIND_IMPL_9,SERILITE_DECLARE_ONE(10)
#define SERILITE_VAR_BIND_IMPL_11 SERILITE_VAR_BIND_IMPL_10,SERILITE_DECLARE_ONE(11)
#define SERILITE_VAR_BIND_IMPL_12 SERILITE_VAR_BIND_IMPL_11,SERILITE_DECLARE_ONE(12)
#define SERILITE_VAR_BIND_IMPL_13 SERILITE_VAR_BIND_IMPL_12,SERILITE_DECLARE_ONE(13)
#define SERILITE_VAR_BIND_IMPL_14 SERILITE_VAR_BIND_IMPL_13,SERILITE_DECLARE_ONE(14)
#define SERILITE_VAR_BIND_IMPL_15 SERILITE_VAR_BIND_IMPL_14,SERILITE_DECLARE_ONE(15)
#define SERILITE_VAR_BIND_IMPL_16 SERILITE_VAR_BIND_IMPL_15,SERILITE_DECLARE_ONE(16)
#define SERILITE_VAR_BIND_IMPL_17 SERILITE_VAR_BIND_IMPL_16,SERILITE_DECLARE_ONE(17)
#define SERILITE_VAR_BIND_IMPL_18 SERILITE_VAR_BIND_IMPL_17,SERILITE_DECLARE_ONE(18)
#define SERILITE_VAR_BIND_IMPL_19 SERILITE_VAR_BIND_IMPL_18,SERILITE_DECLARE_ONE(19)
#define SERILITE_VAR_BIND_IMPL_20 SERILITE_VAR_BIND_IMPL_19,SERILITE_DECLARE_ONE(20)
#define SERILITE_VAR_BIND_IMPL_21 SERILITE_VAR_BIND_IMPL_20,SERILITE_DECLARE_ONE(21)
#define SERILITE_VAR_BIND_IMPL_22 SERILITE_VAR_BIND_IMPL_21,SERILITE_DECLARE_ONE(22)
#define SERILITE_VAR_BIND_IMPL_23 SERILITE_VAR_BIND_IMPL_22,SERILITE_DECLARE_ONE(23)
#define SERILITE_VAR_BIND_IMPL_24 SERILITE_VAR_BIND_IMPL_23,SERILITE_DECLARE_ONE(24)
#define SERILITE_VAR_BIND_IMPL_25 SERILITE_VAR_BIND_IMPL_24,SERILITE_DECLARE_ONE(25)
#define SERILITE_VAR_BIND_IMPL_26 SERILITE_VAR_BIND_IMPL_25,SERILITE_DECLARE_ONE(26)
#define SERILITE_VAR_BIND_IMPL_27 SERILITE_VAR_BIND_IMPL_26,SERILITE_DECLARE_ONE(27)
#define SERILITE_VAR_BIND_IMPL_28 SERILITE_VAR_BIND_IMPL_27,SERILITE_DECLARE_ONE(28)
#define SERILITE_VAR_BIND_IMPL_29 SERILITE_VAR_BIND_IMPL_28,SERILITE_DECLARE_ONE(29)
#define SERILITE_VAR_BIND_IMPL_30 SERILITE_VAR_BIND_IMPL_29,SERILITE_DECLARE_ONE(30)
#define SERILITE_VAR_BIND_IMPL_31 SERILITE_VAR_BIND_IMPL_30,SERILITE_DECLARE_ONE(31)
#define SERILITE_VAR_BIND_IMPL_32 SERILITE_VAR_BIND_IMPL_31,SERILITE_DECLARE_ONE(32)
#define SERILITE_VAR_BIND_IMPL_33 SERILITE_VAR_BIND_IMPL_32,SERILITE_DECLARE_ONE(33)
#define SERILITE_VAR_BIND_IMPL_34 SERILITE_VAR_BIND_IMPL_33,SERILITE_DECLARE_ONE(34)
#define SERILITE_VAR_BIND_IMPL_35 SERILITE_VAR_BIND_IMPL_34,SERILITE_DECLARE_ONE(35)
#define SERILITE_VAR_BIND_IMPL_36 SERILITE_VAR_BIND_IMPL_35,SERILITE_DECLARE_ONE(36)
#define SERILITE_VAR_BIND_IMPL_37 SERILITE_VAR_BIND_IMPL_36,SERILITE_DECLARE_ONE(37)
#define SERILITE_VAR_BIND_IMPL_38 SERILITE_VAR_BIND_IMPL_37,SERILITE_DECLARE_ONE(38)
#define SERILITE_VAR_BIND_IMPL_39 SERILITE_VAR_BIND_IMPL_38,SERILITE_DECLARE_ONE(39)
#define SERILITE_VAR_BIND_IMPL_40 SERILITE_VAR_BIND_IMPL_39,SERILITE_DECLARE_ONE(40)
#define SERILITE_VAR_BIND_IMPL_41 SERILITE_VAR_BIND_IMPL_40,SERILITE_DECLARE_ONE(41)
#define SERILITE_VAR_BIND_IMPL_42 SERILITE_VAR_BIND_IMPL_41,SERILITE_DECLARE_ONE(42)
#define SERILITE_VAR_BIND_IMPL_43 SERILITE_VAR_BIND_IMPL_42,SERILITE_DECLARE_ONE(43)
#define SERILITE_VAR_BIND_IMPL_44 SERILITE_VAR_BIND_IMPL_43,SERILITE_DECLARE_ONE(44)
#define SERILITE_VAR_BIND_IMPL_45 SERILITE_VAR_BIND_IMPL_44,SERILITE_DECLARE_ONE(45)
#define SERILITE_VAR_BIND_IMPL_46 SERILITE_VAR_BIND_IMPL_45,SERILITE_DECLARE_ONE(46)
#define SERILITE_VAR_BIND_IMPL_47 SERILITE_VAR_BIND_IMPL_46,SERILITE_DECLARE_ONE(47)
#define SERILITE_VAR_BIND_IMPL_48 SERILITE_VAR_BIND_IMPL_47,SERILITE_DECLARE_ONE(48)
#define SERILITE_VAR_BIND_IMPL_49 SERILITE_VAR_BIND_IMPL_48,SERILITE_DECLARE_ONE(49)
#define SERILITE_VAR_BIND_IMPL_50 SERILITE_VAR_BIND_IMPL_49,SERILITE_DECLARE_ONE(50)
#define SERILITE_VAR_BIND_IMPL_51 SERILITE_VAR_BIND_IMPL_50,SERILITE_DECLARE_ONE(51)
#define SERILITE_VAR_BIND_IMPL_52 SERILITE_VAR_BIND_IMPL_51,SERILITE_DECLARE_ONE(52)
#define SERILITE_VAR_BIND_IMPL_53 SERILITE_VAR_BIND_IMPL_52,SERILITE_DECLARE_ONE(53)
#define SERILITE_VAR_BIND_IMPL_54 SERILITE_VAR_BIND_IMPL_53,SERILITE_DECLARE_ONE(54)
#define SERILITE_VAR_BIND_IMPL_55 SERILITE_VAR_BIND_IMPL_54,SERILITE_DECLARE_ONE(55)
#define SERILITE_VAR_BIND_IMPL_56 SERILITE_VAR_BIND_IMPL_55,SERILITE_DECLARE_ONE(56)
#define SERILITE_VAR_BIND_IMPL_57 SERILITE_VAR_BIND_IMPL_56,SERILITE_DECLARE_ONE(57)
#define SERILITE_VAR_BIND_IMPL_58 SERILITE_VAR_BIND_IMPL_57,SERILITE_DECLARE_ONE(58)
#define SERILITE_VAR_BIND_IMPL_59 SERILITE_VAR_BIND_IMPL_58,SERILITE_DECLARE_ONE(59)
#define SERILITE_VAR_BIND_IMPL_60 SERILITE_VAR_BIND_IMPL_59,SERILITE_DECLARE_ONE(60)
#define SERILITE_VAR_BIND_IMPL_61 SERILITE_VAR_BIND_IMPL_60,SERILITE_DECLARE_ONE(61)
#define SERILITE_VAR_BIND_IMPL_62 SERILITE_VAR_BIND_IMPL_61,SERILITE_DECLARE_ONE(62)
#define SERILITE_VAR_BIND_IMPL_63 SERILITE_VAR_BIND_IMPL_62,SERILITE_DECLARE_ONE(63)
#define SERILITE_VAR_BIND_IMPL_64 SERILITE_VAR_BIND_IMPL_63,SERILITE_DECLARE_ONE(64)


#define SERILITE_REPEAT_1(macro,...) macro(1, __VA_ARGS__)
#define SERILITE_REPEAT_2(macro,...) SERILITE_REPEAT_1(macro, __VA_ARGS__) macro(2, __VA_ARGS__)
#define SERILITE_REPEAT_3(macro,...) SERILITE_REPEAT_2(macro, __VA_ARGS__) macro(3, __VA_ARGS__)
#define SERILITE_REPEAT_4(macro,...) SERILITE_REPEAT_3(macro, __VA_ARGS__) macro(4, __VA_ARGS__)
#define SERILITE_REPEAT_5(macro,...) SERILITE_REPEAT_4(macro, __VA_ARGS__) macro(5, __VA_ARGS__)
#define SERILITE_REPEAT_6(macro,...) SERILITE_REPEAT_5(macro, __VA_ARGS__) macro(6, __VA_ARGS__)
#define SERILITE_REPEAT_7(macro,...) SERILITE_REPEAT_6(macro, __VA_ARGS__) macro(7, __VA_ARGS__)
#define SERILITE_REPEAT_8(macro,...) SERILITE_REPEAT_7(macro, __VA_ARGS__) macro(8, __VA_ARGS__)
#define SERILITE_REPEAT_9(macro,...) SERILITE_REPEAT_8(macro, __VA_ARGS__) macro(9, __VA_ARGS__)
#define SERILITE_REPEAT_10(macro,...) SERILITE_REPEAT_9(macro, __VA_ARGS__) macro(10, __VA_ARGS__)
#define SERILITE_REPEAT_11(macro,...) SERILITE_REPEAT_10(macro, __VA_ARGS__) macro(11, __VA_ARGS__)
#define SERILITE_REPEAT_12(macro,...) SERILITE_REPEAT_11(macro, __VA_ARGS__) macro(12, __VA_ARGS__)
#define SERILITE_REPEAT_13(macro,...) SERILITE_REPEAT_12(macro, __VA_ARGS__) macro(13, __VA_ARGS__)
#define SERILITE_REPEAT_14(macro,...) SERILITE_REPEAT_13(macro, __VA_ARGS__) macro(14, __VA_ARGS__)
#define SERILITE_REPEAT_15(macro,...) SERILITE_REPEAT_14(macro, __VA_ARGS__) macro(15, __VA_ARGS__)
#define SERILITE_REPEAT_16(macro,...) SERILITE_REPEAT_15(macro, __VA_ARGS__) macro(16, __VA_ARGS__)
#define SERILITE_REPEAT_17(macro,...) SERILITE_REPEAT_16(macro, __VA_ARGS__) macro(17, __VA_ARGS__)
#define SERILITE_REPEAT_18(macro,...) SERILITE_REPEAT_17(macro, __VA_ARGS__) macro(18, __VA_ARGS__)
#define SERILITE_REPEAT_19(macro,...) SERILITE_REPEAT_18(macro, __VA_ARGS__) macro(19, __VA_ARGS__)
#define SERILITE_REPEAT_20(macro,...) SERILITE_REPEAT_19(macro, __VA_ARGS__) macro(20, __VA_ARGS__)
#define SERILITE_REPEAT_21(macro,...) SERILITE_REPEAT_20(macro, __VA_ARGS__) macro(21, __VA_ARGS__)
#define SERILITE_REPEAT_22(macro,...) SERILITE_REPEAT_21(macro, __VA_ARGS__) macro(22, __VA_ARGS__)
#define SERILITE_REPEAT_23(macro,...) SERILITE_REPEAT_22(macro, __VA_ARGS__) macro(23, __VA_ARGS__)
#define SERILITE_REPEAT_24(macro,...) SERILITE_REPEAT_23(macro, __VA_ARGS__) macro(24, __VA_ARGS__)
#define SERILITE_REPEAT_25(macro,...) SERILITE_REPEAT_24(macro, __VA_ARGS__) macro(25, __VA_ARGS__)
#define SERILITE_REPEAT_26(macro,...) SERILITE_REPEAT_25(macro, __VA_ARGS__) macro(26, __VA_ARGS__)
#define SERILITE_REPEAT_27(macro,...) SERILITE_REPEAT_26(macro, __VA_ARGS__) macro(27, __VA_ARGS__)
#define SERILITE_REPEAT_28(macro,...) SERILITE_REPEAT_27(macro, __VA_ARGS__) macro(28, __VA_ARGS__)
#define SERILITE_REPEAT_29(macro,...) SERILITE_REPEAT_28(macro, __VA_ARGS__) macro(29, __VA_ARGS__)
#define SERILITE_REPEAT_30(macro,...) SERILITE_REPEAT_29(macro, __VA_ARGS__) macro(30, __VA_ARGS__)
#define SERILITE_REPEAT_31(macro,...) SERILITE_REPEAT_30(macro, __VA_ARGS__) macro(31, __VA_ARGS__)
#define SERILITE_REPEAT_32(macro,...) SERILITE_REPEAT_31(macro, __VA_ARGS__) macro(32, __VA_ARGS__)
#define SERILITE_REPEAT_33(macro,...) SERILITE_REPEAT_32(macro, __VA_ARGS__) macro(33, __VA_ARGS__)
#define SERILITE_REPEAT_34(macro,...) SERILITE_REPEAT_33(macro, __VA_ARGS__) macro(34, __VA_ARGS__)
#define SERILITE_REPEAT_35(macro,...) SERILITE_REPEAT_34(macro, __VA_ARGS__) macro(35, __VA_ARGS__)
#define SERILITE_REPEAT_36(macro,...) SERILITE_REPEAT_35(macro, __VA_ARGS__) macro(36, __VA_ARGS__)
#define SERILITE_REPEAT_37(macro,...) SERILITE_REPEAT_36(macro, __VA_ARGS__) macro(37, __VA_ARGS__)
#define SERILITE_REPEAT_38(macro,...) SERILITE_REPEAT_37(macro, __VA_ARGS__) macro(38, __VA_ARGS__)
#define SERILITE_REPEAT_39(macro,...) SERILITE_REPEAT_38(macro, __VA_ARGS__) macro(39, __VA_ARGS__)
#define SERILITE_REPEAT_40(macro,...) SERILITE_REPEAT_39(macro, __VA_ARGS__) macro(40, __VA_ARGS__)
#define SERILITE_REPEAT_41(macro,...) SERILITE_REPEAT_40(macro, __VA_ARGS__) macro(41, __VA_ARGS__)
#define SERILITE_REPEAT_42(macro,...) SERILITE_REPEAT_41(macro, __VA_ARGS__) macro(42, __VA_ARGS__)
#define SERILITE_REPEAT_43(macro,...) SERILITE_REPEAT_42(macro, __VA_ARGS__) macro(43, __VA_ARGS__)
#define SERILITE_REPEAT_44(macro,...) SERILITE_REPEAT_43(macro, __VA_ARGS__) macro(44, __VA_ARGS__)
#define SERILITE_REPEAT_45(macro,...) SERILITE_REPEAT_44(macro, __VA_ARGS__) macro(45, __VA_ARGS__)
#define SERILITE_REPEAT_46(macro,...) SERILITE_REPEAT_45(macro, __VA_ARGS__) macro(46, __VA_ARGS__)
#define SERILITE_REPEAT_47(macro,...) SERILITE_REPEAT_46(macro, __VA_ARGS__) macro(47, __VA_ARGS__)
#define SERILITE_REPEAT_48(macro,...) SERILITE_REPEAT_47(macro, __VA_ARGS__) macro(48, __VA_ARGS__)
#define SERILITE_REPEAT_49(macro,...) SERILITE_REPEAT_48(macro, __VA_ARGS__) macro(49, __VA_ARGS__)
#define SERILITE_REPEAT_50(macro,...) SERILITE_REPEAT_49(macro, __VA_ARGS__) macro(50, __VA_ARGS__)
#define SERILITE_REPEAT_51(macro,...) SERILITE_REPEAT_50(macro, __VA_ARGS__) macro(51, __VA_ARGS__)
#define SERILITE_REPEAT_52(macro,...) SERILITE_REPEAT_51(macro, __VA_ARGS__) macro(52, __VA_ARGS__)
#define SERILITE_REPEAT_53(macro,...) SERILITE_REPEAT_52(macro, __VA_ARGS__) macro(53, __VA_ARGS__)
#define SERILITE_REPEAT_54(macro,...) SERILITE_REPEAT_53(macro, __VA_ARGS__) macro(54, __VA_ARGS__)
#define SERILITE_REPEAT_55(macro,...) SERILITE_REPEAT_54(macro, __VA_ARGS__) macro(55, __VA_ARGS__)
#define SERILITE_REPEAT_56(macro,...) SERILITE_REPEAT_55(macro, __VA_ARGS__) macro(56, __VA_ARGS__)
#define SERILITE_REPEAT_57(macro,...) SERILITE_REPEAT_56(macro, __VA_ARGS__) macro(57, __VA_ARGS__)
#define SERILITE_REPEAT_58(macro,...) SERILITE_REPEAT_57(macro, __VA_ARGS__) macro(58, __VA_ARGS__)
#define SERILITE_REPEAT_59(macro,...) SERILITE_REPEAT_58(macro, __VA_ARGS__) macro(59, __VA_ARGS__)
#define SERILITE_REPEAT_60(macro,...) SERILITE_REPEAT_59(macro, __VA_ARGS__) macro(60, __VA_ARGS__)
#define SERILITE_REPEAT_61(macro,...) SERILITE_REPEAT_60(macro, __VA_ARGS__) macro(61, __VA_ARGS__)
#define SERILITE_REPEAT_62(macro,...) SERILITE_REPEAT_61(macro, __VA_ARGS__) macro(62, __VA_ARGS__)
#define SERILITE_REPEAT_63(macro,...) SERILITE_REPEAT_62(macro, __VA_ARGS__) macro(63, __VA_ARGS__)
#define SERILITE_REPEAT_64(macro,...) SERILITE_REPEAT_63(macro, __VA_ARGS__) macro(64, __VA_ARGS__)

#define SERILITE_VAR_BIND(x) SERILITE_VAR_BIND_IMPL_##x

#define SERILITE_REPEAT(x,macro,...) SERILITE_REPEAT_##x(macro, __VA_ARGS__)

#define FOR_EACH_FIELD(i, func, ...) func(_BINDS_VAR_##i, ##__VA_ARGS__);

// clang-format on
namespace serilite {
namespace details {

template <size_t N>
using constant_size_t = std::integral_constant<size_t, N>;

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<1>) {
    auto& [SERILITE_VAR_BIND(1)] = value;
    SERILITE_REPEAT(1, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<2>) {
    auto& [SERILITE_VAR_BIND(2)] = value;
    SERILITE_REPEAT(2, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<3>) {
    auto& [SERILITE_VAR_BIND(3)] = value;
    SERILITE_REPEAT(3, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<4>) {
    auto& [SERILITE_VAR_BIND(4)] = value;
    SERILITE_REPEAT(4, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<5>) {
    auto& [SERILITE_VAR_BIND(5)] = value;
    SERILITE_REPEAT(5, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<6>) {
    auto& [SERILITE_VAR_BIND(6)] = value;
    SERILITE_REPEAT(6, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<7>) {
    auto& [SERILITE_VAR_BIND(7)] = value;
    SERILITE_REPEAT(7, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<8>) {
    auto& [SERILITE_VAR_BIND(8)] = value;
    SERILITE_REPEAT(8, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func, constant_size_t<9>) {
    auto& [SERILITE_VAR_BIND(9)] = value;
    SERILITE_REPEAT(9, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<10>) {
    auto& [SERILITE_VAR_BIND(10)] = value;
    SERILITE_REPEAT(10, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<11>) {
    auto& [SERILITE_VAR_BIND(11)] = value;
    SERILITE_REPEAT(11, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<12>) {
    auto& [SERILITE_VAR_BIND(12)] = value;
    SERILITE_REPEAT(12, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<13>) {
    auto& [SERILITE_VAR_BIND(13)] = value;
    SERILITE_REPEAT(13, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<14>) {
    auto& [SERILITE_VAR_BIND(14)] = value;
    SERILITE_REPEAT(14, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<15>) {
    auto& [SERILITE_VAR_BIND(15)] = value;
    SERILITE_REPEAT(15, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<16>) {
    auto& [SERILITE_VAR_BIND(16)] = value;
    SERILITE_REPEAT(16, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<17>) {
    auto& [SERILITE_VAR_BIND(17)] = value;
    SERILITE_REPEAT(17, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<18>) {
    auto& [SERILITE_VAR_BIND(18)] = value;
    SERILITE_REPEAT(18, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<19>) {
    auto& [SERILITE_VAR_BIND(19)] = value;
    SERILITE_REPEAT(19, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<20>) {
    auto& [SERILITE_VAR_BIND(20)] = value;
    SERILITE_REPEAT(20, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<21>) {
    auto& [SERILITE_VAR_BIND(21)] = value;
    SERILITE_REPEAT(21, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<22>) {
    auto& [SERILITE_VAR_BIND(22)] = value;
    SERILITE_REPEAT(22, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<23>) {
    auto& [SERILITE_VAR_BIND(23)] = value;
    SERILITE_REPEAT(23, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<24>) {
    auto& [SERILITE_VAR_BIND(24)] = value;
    SERILITE_REPEAT(24, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<25>) {
    auto& [SERILITE_VAR_BIND(25)] = value;
    SERILITE_REPEAT(25, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<26>) {
    auto& [SERILITE_VAR_BIND(26)] = value;
    SERILITE_REPEAT(26, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<27>) {
    auto& [SERILITE_VAR_BIND(27)] = value;
    SERILITE_REPEAT(27, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<28>) {
    auto& [SERILITE_VAR_BIND(28)] = value;
    SERILITE_REPEAT(28, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<29>) {
    auto& [SERILITE_VAR_BIND(29)] = value;
    SERILITE_REPEAT(29, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<30>) {
    auto& [SERILITE_VAR_BIND(30)] = value;
    SERILITE_REPEAT(30, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<31>) {
    auto& [SERILITE_VAR_BIND(31)] = value;
    SERILITE_REPEAT(31, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<32>) {
    auto& [SERILITE_VAR_BIND(32)] = value;
    SERILITE_REPEAT(32, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<33>) {
    auto& [SERILITE_VAR_BIND(33)] = value;
    SERILITE_REPEAT(33, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<34>) {
    auto& [SERILITE_VAR_BIND(34)] = value;
    SERILITE_REPEAT(34, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<35>) {
    auto& [SERILITE_VAR_BIND(35)] = value;
    SERILITE_REPEAT(35, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<36>) {
    auto& [SERILITE_VAR_BIND(36)] = value;
    SERILITE_REPEAT(36, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<37>) {
    auto& [SERILITE_VAR_BIND(37)] = value;
    SERILITE_REPEAT(37, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<38>) {
    auto& [SERILITE_VAR_BIND(38)] = value;
    SERILITE_REPEAT(38, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<39>) {
    auto& [SERILITE_VAR_BIND(39)] = value;
    SERILITE_REPEAT(39, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<40>) {
    auto& [SERILITE_VAR_BIND(40)] = value;
    SERILITE_REPEAT(40, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<41>) {
    auto& [SERILITE_VAR_BIND(41)] = value;
    SERILITE_REPEAT(41, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<42>) {
    auto& [SERILITE_VAR_BIND(42)] = value;
    SERILITE_REPEAT(42, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<43>) {
    auto& [SERILITE_VAR_BIND(43)] = value;
    SERILITE_REPEAT(43, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<44>) {
    auto& [SERILITE_VAR_BIND(44)] = value;
    SERILITE_REPEAT(44, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<45>) {
    auto& [SERILITE_VAR_BIND(45)] = value;
    SERILITE_REPEAT(45, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<46>) {
    auto& [SERILITE_VAR_BIND(46)] = value;
    SERILITE_REPEAT(46, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<47>) {
    auto& [SERILITE_VAR_BIND(47)] = value;
    SERILITE_REPEAT(47, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<48>) {
    auto& [SERILITE_VAR_BIND(48)] = value;
    SERILITE_REPEAT(48, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<49>) {
    auto& [SERILITE_VAR_BIND(49)] = value;
    SERILITE_REPEAT(49, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<50>) {
    auto& [SERILITE_VAR_BIND(50)] = value;
    SERILITE_REPEAT(50, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<51>) {
    auto& [SERILITE_VAR_BIND(51)] = value;
    SERILITE_REPEAT(51, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<52>) {
    auto& [SERILITE_VAR_BIND(52)] = value;
    SERILITE_REPEAT(52, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<53>) {
    auto& [SERILITE_VAR_BIND(53)] = value;
    SERILITE_REPEAT(53, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<54>) {
    auto& [SERILITE_VAR_BIND(54)] = value;
    SERILITE_REPEAT(54, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<55>) {
    auto& [SERILITE_VAR_BIND(55)] = value;
    SERILITE_REPEAT(55, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<56>) {
    auto& [SERILITE_VAR_BIND(56)] = value;
    SERILITE_REPEAT(56, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<57>) {
    auto& [SERILITE_VAR_BIND(57)] = value;
    SERILITE_REPEAT(57, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<58>) {
    auto& [SERILITE_VAR_BIND(58)] = value;
    SERILITE_REPEAT(58, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<59>) {
    auto& [SERILITE_VAR_BIND(59)] = value;
    SERILITE_REPEAT(59, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<60>) {
    auto& [SERILITE_VAR_BIND(60)] = value;
    SERILITE_REPEAT(60, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<61>) {
    auto& [SERILITE_VAR_BIND(61)] = value;
    SERILITE_REPEAT(61, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<62>) {
    auto& [SERILITE_VAR_BIND(62)] = value;
    SERILITE_REPEAT(62, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<63>) {
    auto& [SERILITE_VAR_BIND(63)] = value;
    SERILITE_REPEAT(63, FOR_EACH_FIELD, func);
}

template <typename T, typename ExecFunc>
void foreach_over_elements_impl(T& value, ExecFunc&& func,
                                constant_size_t<64>) {
    auto& [SERILITE_VAR_BIND(64)] = value;
    SERILITE_REPEAT(64, FOR_EACH_FIELD, func);
}

}  // namespace details

}  // namespace serilite
