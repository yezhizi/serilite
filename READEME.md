# serilite
serilite is designed to be a simple and easy to use serialization library for C++17. 
You can easily serialize and deserialize your objects with just a few lines of code 
and without any boilerplate code.
For example, you can serialize a simple object like this:
```cpp
#include <serilite.hpp>
YourObject obj;
auto serialized = serilite::serialize(obj).to_string();
// ....
YourObject obj2
serilite::deserialize(serialized,obj2);
```

No need to write any serialization or deserialization code for your objects or modify them in any way.

## Supported types
srilite supports the most of frequently used types, including:
- [Trivially copyable type](https://en.cppreference.com/w/cpp/named_req/TriviallyCopyable)
- Can be constructed by `std::memcpy` from a byte representation. This includes all scalar types, arrays or vector of trivially copyable types.
- Has iterator, which means `T::iterator` and `T::value_type` are defined.
- [Aggregate type](https://en.cppreference.com/w/cpp/language/aggregate_initialization) with fileds of supported types, and fileds count less than 64.
- `std::tuple` and `std::pair` of supported types.


## References
[C++序列化对象](https://www.cnblogs.com/mmc1206x/p/11053826.html)
[Counting the number of fields in an aggregate in C++20](https://towardsdev.com/counting-the-number-of-fields-in-an-aggregate-in-c-20-c81aecfd725c)