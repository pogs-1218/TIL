#ifndef BRIDGE_IMPLEMENTOR1_H_
#define BRIDGE_IMPLEMENTOR1_H_

#include <iostream>
#include "implementor.h"

class Implementor1 : public Implementor{
 public:
  ~Implementor1() override = default;
  
  void Operation() override{
    std::cout << "Implementor1's operation\n";
  }
};

#endif
