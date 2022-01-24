#ifndef LEAF_H_
#define LEAF_H_

#include "component.h"

class Leaf : public Component {
 public:
  Leaf(const std::string& name) : Component(name) {}

  std::string Operation() override { return name(); }
};

#endif
