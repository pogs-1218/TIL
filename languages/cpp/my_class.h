#include <iostream>

// constexpr

class Rect {
 public:
  constexpr Rect(std::size_t width, std::size_t height)
      : width_{width}, height_{height} {}
  constexpr std::size_t GetArea() const { return width_ * height_; }

 private:
  std::size_t width_{0};
  std::size_t height_{0};
};

class TestClass {
 public:
  TestClass() { std::cout << "Constructor\n"; }
  ~TestClass() { std::cout << "Destructor\n"; }

  TestClass(const TestClass& ohs) { std::cout << "Copy constructor\n"; }

  TestClass& operator=(const TestClass& ohs) {
    std::cout << "Copy assign\n";
    return *this;
  }
};
