#include <iostream>
#include <memory>

#define DISALLOW_COPY(class)    \
  class(const class&) = delete; \
  class& operator=(const class&) = delete;

class Simple {
 public:
  Simple() { std::cout << "Create Simple" << std::endl; }
  ~Simple() { std::cout << "Destroy Simple" << std::endl; }

  Simple(Simple&& other) {
    std::cout << "move constructor" << std::endl;
    value_ = other.value_;
  }

  Simple& operator=(Simple&& other) {
    std::cout << "move assignment" << std::endl;
    value_ = other.value_;
    return *this;
  }

  DISALLOW_COPY(Simple)

  void set_value(int value) { value_ = value; }
  int value() const { return value_; }

 private:
  int value_;
};

class Foo {
 public:
  Foo(std::unique_ptr<Simple> simple) : simple_{std::move(simple)} {}

 private:
  std::unique_ptr<Simple> simple_;
};

class Boo {
 public:
  Boo(std::shared_ptr<Simple> simple) : simple_{simple} {
    std::cout << "shared simpel is copied [" << simple_.use_count() << "]"
              << std::endl;
  }

 private:
  std::shared_ptr<Simple> simple_;
};

int* my_alloc(int value) { return new int{value}; }
void my_free(int* p) { delete p; }

void UseUniquePtr(std::unique_ptr<Simple> simple) { simple->set_value(5); }

void UseSharedPtr(std::shared_ptr<Simple> simple) {
  std::cout << simple.use_count() << std::endl;
  simple->set_value(2);
}

std::unique_ptr<Simple> MakeUniquePtr(Simple* simple) {
  return std::unique_ptr<Simple>(simple);
}

int main() {
  Foo foo{std::make_unique<Simple>()};

  auto my_simple1{std::make_unique<Simple>()};
  Foo foo2{std::move(my_simple1)};

  std::unique_ptr<int, decltype(&my_free)> my_int{my_alloc(32), my_free};
  std::cout << *my_int << std::endl;

  auto simple2 = std::make_unique<Simple>();
  UseUniquePtr(std::move(simple2));
  // std::cout << simple2->value() << std::endl;

  auto shared_simple = std::make_shared<Simple>();
  std::cout << shared_simple.use_count() << std::endl;

  Boo boo(shared_simple);
  std::cout << shared_simple.use_count() << std::endl;

  UseSharedPtr(shared_simple);
  std::cout << shared_simple.use_count() << std::endl;

  return 0;
}