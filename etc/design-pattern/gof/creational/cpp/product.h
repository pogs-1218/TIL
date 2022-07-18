#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>

class Product {
public:
  virtual ~Product() = default;
  virtual void Operation() = 0;
};

class MyProduct : public Product {
public:
  ~MyProduct() override {}

  void Operation() override {
    std::cout << "MyProduct Operation" << std::endl;
  }
};

class OhProduct : public Product {
public:
  ~OhProduct() override {}

  void Operation() override {
    std::cout << "OhProduct Operation" << std::endl;
  }
};


#endif
