#include <array>
#include <charconv>  // to_chars
#include <cstring>   // memset
#include <initializer_list>
#include <iostream>
#include <optional>  // optional
#include <string>
#include <string_view>
#include <utility>  // pair
#include <vector>
#include <list>

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

void TestCasting(int i) {
  // nothing
}

int MakeSum(std::initializer_list<int> values) {
  int total{0};
  for (int value : values) {
    total += value;
  }
  return total;
}

std::string_view ExtractExtension(std::string_view filename) {
  return filename.substr(filename.rfind('.'));
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
  std::string mysting = "test";

  std::pair my_pairn{"string", 1.2};
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

  const char* rawstr{R"(Hello "World"!)"};
  std::cout << rawstr << std::endl;

  std::string s1 = "123";
  std::string s2 = "123";
  auto comp{s1 <=> s2};  // since c++20
  if (std::is_lt(comp)) std::cout << "less" << std::endl;
  if (std::is_gt(comp)) std::cout << "greater" << std::endl;
  if (std::is_eq(comp)) std::cout << "equal" << std::endl;

  std::string full_str = "hello,world";
  std::cout << full_str.substr(6, 5) << std::endl;

  using namespace std::string_literals;
  std::vector const_char_vec{"john", "sam", "doe"};
  std::vector string_vec{"john"s, "sam"s, "doe"s};

  // Should I know below? to_chars, from_chars. why needed? performance?
  const std::size_t buffer_size = 50;
  std::string out(buffer_size, ' ');
  auto result{std::to_chars(out.data(), out.data() + out.size(), 12345)};
  if (result.ec == std::errc{}) std::cout << out << std::endl;

  // Have to know what is overcomed by using string_view.
  // Have to know string and string_view casting.
  // Have to know the life time.(memory problem)
  std::string origin_string = "test.txt";
  std::cout << ExtractExtension(origin_string) << std::endl;
  std::cout << ExtractExtension("file.txt") << std::endl;

  // new vs malloc
  TestClass* tc_malloc{(TestClass*)malloc(sizeof(TestClass))};
  TestClass* tc_new{new TestClass()};

  // if there is not enough memory? how to recover?
  // NOTE: How to produce that situation by myself?
  int* int_ptr{new (std::nothrow) int};

  // Initialize an array with variable ways.
  // NOTE: Different performance ?
  int int_arr1[5]{};
  int int_arr2[5];
  memset(int_arr2, 0, sizeof(int_arr2));
  int int_arr3[5];
  std::fill(int_arr3, int_arr3 + sizeof(int_arr3), 0);

  // std::size, since c++17
  std::cout << std::size(int_arr2) << std::endl;

  return 0;
}
