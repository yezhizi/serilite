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

class EnumClass{
    public:
        E e;
        old_enum oe;
        EnumClass(): e(E::A), oe(E2){};
        EnumClass(E e, old_enum oe): e(e), oe(oe){};
};

#define CHECK_GE(a, b) do { if (!(a >= b)) { std::cout << "CHECK_GE failed: " << a << " >= " << b << std::endl; exit(1); } } while(0)
#define CHECK_EQ(a, b) do { if (!(a == b)) { std::cout << "CHECK_EQ failed: " << a << " == " << b << std::endl; exit(1); } } while(0)
#define CHECK_NE(a, b) do { if (!(a != b)) { std::cout << "CHECK_NE failed: " << a << " != " << b << std::endl; exit(1); } } while(0)

/** @brief Overlay topology*/
using AdjacencyList = std::unordered_map<int, std::vector<int>>;
/** @brief Node transport topology.
 * including member parent and children
 * @param `type`: the `type` of this node, `kRoot` - root node, `kLeaf` - leaf node,
 * `kInner` - inner node and `kUnset` - unset
 * - parent: the parent of this node, only valid for inner and leaf nodes
 * - children: the children of this node
 */
class NodeTransTopo {
 public:
  enum class Type {
    kRoot,
    kLeaf,
    kInner,
    kUnset,
  };

//   NodeTransTopo() : type_(Type::kUnset), parent_(0) {}
  NodeTransTopo() = default;
//   NodeTransTopo(const NodeTransTopo& other) {
//     type_ = other.type_;
//     parent_ = other.parent_;
//     children_ = other.children_;
//   }
NodeTransTopo(const NodeTransTopo& other) = default;
//   NodeTransTopo(NodeTransTopo&& other) noexcept {
//     type_ = other.type_;
//     parent_ = other.parent_;
//     children_ = std::move(other.children_);
//   }
NodeTransTopo(NodeTransTopo&& other) noexcept = default;
  NodeTransTopo& operator=(const NodeTransTopo& other) {
    if (this == &other) {
      return *this;
    }
    type_ = other.type_;
    parent_ = other.parent_;
    children_ = other.children_;
    return *this;
  }
  NodeTransTopo& operator=(NodeTransTopo&& other) noexcept {
    if (this == &other) {
      return *this;
    }
    type_ = other.type_;
    parent_ = other.parent_;
    children_ = std::move(other.children_);
    return *this;
  }

  Type getType() const {
    return type_;
  }

  int getParent() const {
    return parent_;
  }

  const std::vector<int>& getChildren() const {
    return children_;
  }

  bool setoRoot() {
    if (this->parent_ == 0) {
      this->type_ = Type::kRoot;
      return true;
    }
    return false;
  }

  void setParent(int parent) {
    CHECK_GE(parent, -1);
    parent_ = parent;
    type_ = children_.size() > 0 ? Type::kInner : Type::kLeaf;
  }

  void addChildren(int child) {
    CHECK_GE(child, -1);
    children_.push_back(child);
    type_ = type_ == Type::kLeaf ? Type::kInner : Type::kRoot;
  }

  std::string Encode() const {
    std::ostringstream oss;
    oss << static_cast<int>(type_) << " " << parent_<<" ";
    oss << children_.size()<<" ";
    for (const auto& child : children_) {
      oss << child << " ";
    }
    return oss.str();
  }

  void Decode(std::istringstream& iss) {
    children_.clear();
    int temp;
    iss >> temp;
    type_ = static_cast<Type>(temp);
    iss >> parent_;
    iss >> temp;
    children_.resize(temp);
    for (int i = 0; i < temp; ++i) {
      iss >> children_[i];
    }
  }

//  private:
  Type type_;
  int parent_;
  std::vector<int> children_;
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

    EnumClass ec(E::C, E3);
    auto res8 = serilite::serialize(ec);
    EnumClass res9;
    serilite::deserialize(res8, res9);
    std::cout << "res8: " << res8.as_string() << std::endl;
    std::cout << "res9: " << static_cast<int>(res9.e) << " " << static_cast<int>(res9.oe) << std::endl;

    NodeTransTopo n1;
    n1.addChildren(2);
    n1.addChildren(3);
    

    
    auto res10 = serilite::serialize(n1);
    NodeTransTopo res11;
    serilite::deserialize(res10, res11);
    std::cout << "res10: " << res10.as_string() << std::endl;
    std::cout << "res11: " << static_cast<int>( res11.getType()) << " " << res11.getParent() << " " << res11.getChildren().size() << " " << res11.getChildren()[0] << " " << res11.getChildren()[1] << std::endl;

    using GlobalTransTopo = std::unordered_map<int, NodeTransTopo>;
    GlobalTransTopo gtt;
    gtt[1] = n1;
    gtt[2] = NodeTransTopo();
    auto res111= serilite::serialize(gtt);
    GlobalTransTopo res12;
    serilite::deserialize(res111, res12);
    std::cout << "res12: " << res12.size() << std::endl;

    for (auto const& [key, value] : res12) {
        std::cout << key << " " << static_cast<int>(value.getType()) << " " << value.getParent() << " " << value.getChildren().size() << " " << value.getChildren()[0] << " " << value.getChildren()[1] << std::endl;

    }

    return 0;

}