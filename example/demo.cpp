#include "serilite.hpp"
#include <array>
#include <iostream>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <list>

struct Point
{
  float x;
  float y;
};
enum class Enum {
    e1,
    e2,
    e3,
};


struct X{
  Enum a;
  std::string b ;
  std::vector<int> c ;
  std::tuple<std::array<double,2>,std::string> d ;
  std::unordered_map<char, float> e;
  std::list<Point> f ;
};

int main(){
  X x = {Enum::e1, "hello", {1,2,3}, std::make_tuple(std::array<double,2>{1.0,2.0},std::string("world")), {{'a',1.0},{'b',2.0}}, {{1.0,2.0},{3.0,4.0}}};
  auto s = serilite::serialize(x);
  std::cout << s.as_string_view() << std::endl;
  std::string serialized = s.as_string(); // copy to string
  X x2;
  serilite::deserialize(serialized,x2);
  std::cout << static_cast<int>(x2.a) << std::endl;
  std::cout << x2.b << std::endl;
  for(auto i : x2.c){
    std::cout << i << std::endl;
  }
  auto [a,b] = x2.d;
  std::cout << std::get<0>(a) << std::endl;
  std::cout << std::get<1>(a) << std::endl;
  std::cout << b << std::endl;
  for (auto [k, v] : x2.e) {
      std::cout << k << " " << v << std::endl;
  }
  for(auto p : x2.f){
    std::cout << p.x << " " << p.y << std::endl;
  }
  return 0;
}