#ifndef BRIDGE_ABSTRACTION1_H_
#define BRIDGE_ABSTRACTION1_H_

#include <iostream>

// This may be point. The abstraction1 shouldn't know the detailed implementation.
// Only include implementor interface!
#include "abstraction.h"
#include "implementor.h"

class Abstraction1 : public Abstraction {
 public:
  Abstraction1(Implementor* impl) : impl_(impl) {}
  ~Abstraction1() override = default;

  /* Abstraction1's Operation function is not specified in compile-time
   * since the actual operation of Operation is done by impl_ that is determined in run-time.
   * See the Abstarction1's constructor. */
  void Operation() override {
    std::cout << "Abstration1's operation : ";
    impl_->Operation();
  }

 private:
  Implementor* impl_;
};

#endif
