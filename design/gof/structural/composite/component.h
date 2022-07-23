#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

class Component {
 public:
  Component(const std::string& name) : name_(name) {}

  virtual std::string Operation() = 0;
  virtual bool AddChild(Component* child) { return false; }

  std::string name() { return name_; }

 protected:
  std::string name_;
};

#endif
