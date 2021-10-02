#include <array>
#include <initializer_list>
#include <iostream>
#include <optional>  // optional
#include <utility>   // pair
#include <vector>

#include "my_class.h"

namespace gyungi::anyang {
void func() { std::cout << "Func1\n"; }

[[nodiscard]] int sum(int a, int b) { return a + b; }
}  // namespace gyungi::anyang

namespace myhome = gyungi::anyang;

std::optional<int> GetData(bool give) {
  if (give) {
    return 32;
  }
  return std::nullopt;
}

int MakeSum(std::initializer_list<int> values) {
  int total{0};
  for (int value : values) {
    total += value;
  }
  return total;
}

void TestCasting(int i) {
  // nothing
}

struct Employee {
  char first;
  std::string name;
  int id;
};

void GetStringRef(const std::string& str) { std::cout << str << std::endl; }

const TestClass kTestClass;
const TestClass& GetTestClass() { return kTestClass; }

int main() {
  gyungi::anyang::func();
  // std::cout << myhome::sum(1, 2) << std::endl;
  myhome::sum(1, 2);

  char my_array[3];
  std::cout << std::size(my_array) << std::endl;

  // std::array<int, 3> my_array2 {1, 2, 3};
  std::array my_array2{1, 2, 3};
  std::cout << "size: " << my_array2.size() << std::endl;
  std::cout << "at 2: " << my_array2[1] << std::endl;

  std::vector my_vector{11, 12};
  std::cout << "vector size: " << my_vector.size() << std::endl;

  std::pair my_pair{"string", 1.2};
  std::cout << my_pair.first << ", " << my_pair.second << std::endl;

  std::optional<int> data1{GetData(true)};
  std::optional<int> data2{GetData(false)};
  if (data1.has_value()) {
    std::cout << data1.value() << std::endl;
  }
  std::cout << data2.value_or(0) << std::endl;

  for (std::array arr{1, 2, 3, 4}; int i : arr) {
    std::cout << i << std::endl;
  }

  // int s1 { MakeSum({1, 2, 3}) };
  // std::cout << s1  << std::endl;

  int x = 3.14;
  TestCasting(x);

  // Complile error as narrowing!
  // int xx {3.14};
  // TestCasting( {3.14} );

  Employee employee{.first = 'p', .name = "pigh"};

  constexpr Rect r{8, 2};
  int my_arr[r.GetArea()];

  GetStringRef("hello");

  // auto test_class { GetTestClass() };
  // const auto& test_class { GetTestClass() };
  decltype(GetTestClass()) test_class{GetTestClass()};

  return 0;
}
