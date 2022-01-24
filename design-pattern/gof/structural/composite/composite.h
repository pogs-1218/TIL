#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <list>

#include "component.h"

class Composite : public Component {
 public:
  Composite(const std::string& name) : Component(name) {}

  std::string Operation() override {
    std::string name{name_};
    for (const auto& child : children) {
      name += child->Operation();
    }
    return name;
  }

  bool AddChild(Component* child) override {
    children.push_back(child);
    return true;
  }

 private:
  std::list<Component*> children;
};

#endif
