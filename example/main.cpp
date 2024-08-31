#include "serilite.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <type_traits>
#include <utility>

struct X{
    int a;
    std::string b;
};

struct A{
    int b;
    std::string c;
    X d;
};
enum class E{
    A,
    B,
    C
};
enum old_enum{
    E1,
    E2,
    E3
};

int main(){
    auto res1 = serilite::serialize(46);
    auto res2 = serilite::serialize(std::string{"hello world"});
    auto res3 = serilite::serialize(std::vector<int>{1, 2, 3});
    const auto& map1 = std::unordered_map <int, std::string>{{1, "hello"}, {2, "world"}};
    auto res4 = serilite::serialize(map1);


    auto res44 = serilite::serialize(std::pair<const int, std::string>{1, "hello"});
    auto res5 = serilite::serialize(std::tuple<int, int, double>{1, 2, 3.14});
    auto res6 = serilite::serialize(X{1, "hello"});
    auto res7 = serilite::serialize(A{ 1, "world", X{2, "world"}});

    std::cout << "res1: " << res1.as_string() << std::endl;
    std::cout << "res2: " << res2.as_string() << std::endl;
    std::cout << "res3: " << res3.as_string() << std::endl;
     std::cout << "res44: " << res44.as_string() << std::endl;
    std::cout << "res4: " << res4.as_string() << res4.size() << std::endl;
    std::cout << "res6: " << res6.as_string() << std::endl;
    std::cout << "res7: " << res7.as_string() << std::endl;

    int res1_val;
    std::string res2_val;
    std::vector<int> res3_val;
    X res6_val;
    A res7_val;
    auto res44_val = std::pair<int, std::string>{};
    std::map<int, std::string> res4_val;
    std::tuple<int, int, double> res5_val;
    serilite::deserialize(res1, res1_val);
    serilite::deserialize(res2, res2_val);
    serilite::deserialize(res3, res3_val);
    serilite::deserialize(res4, res4_val);
    serilite::deserialize(res44, res44_val);
    serilite::deserialize(res5, res5_val);
    serilite::deserialize(res6, res6_val);
    serilite::deserialize(res7, res7_val);

    std::cout << "res1_val: " << res1_val << std::endl;
    std::cout << "res2_val: " << res2_val<<" "<<res2_val.size() << std::endl;
    std::cout << "res3_val: " << res3_val.size() << " " <<res3_val[0] << " " << res3_val[1] << " " << res3_val[2] << std::endl;
    for (auto const& [key, value] : res4_val) {
        std::cout << key << " " << value << std::endl;
    }
    std::cout << "res44_val: " << res44_val.first << " " << res44_val.second << std::endl;
    std::cout << "res5_val: " << std::get<0>(res5_val) << " " << std::get<1>(res5_val) << " " << std::get<2>(res5_val) << std::endl;
    std::cout << "res6_val: " << res6_val.a << " " << res6_val.b << std::endl;
    std::cout << "res7_val: " << res7_val.b << " " << res7_val.c << " " << res7_val.d.a << " " << res7_val.d.b << std::endl;

    return 0;
}