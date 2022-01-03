/*
In: two strings
Out: prints them out in alphabetical order. using three-way comparison
*/

#include <iostream>
#include <string>

int main() {
  std::string user_input1;
  std::getline(std::cin, user_input1);

  std::string user_input2;
  std::getline(std::cin, user_input2);

  auto comp{user_input1 <=> user_input2};
  if (std::is_lt(comp)) {
    std::cout << user_input1 << std::endl;
    std::cout << user_input2 << std::endl;
  } else {
    std::cout << user_input2 << std::endl;
    std::cout << user_input1 << std::endl;
  }

  return 0;
}