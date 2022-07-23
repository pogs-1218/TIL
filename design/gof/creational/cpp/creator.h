#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include "product.h"

class Creator{
 public:
  virtual Product* CreateProduct() = 0;
};

class MyCreator : public Creator{
public:
  Product* CreateProduct() override {
    return new MyProduct;
  }
};

class OhCreator : public Creator {
public:
  Product* CreateProduct() override {
    return new OhProduct;
  }
};


enum class ProductType{
  My, Oh
};

class ParamCreator {
public:
  virtual Product* CreateProduct(ProductType type) {
    if(type == ProductType::My) return new MyProduct;
    if(type == ProductType::Oh) return new OhProduct;
    return nullptr;
  }
}

template <typename ProductType>
class StandardCreator : public Creator{
public:
  Product* CreateProduct() override{
    return new ProductType;
  }
};

#endif
