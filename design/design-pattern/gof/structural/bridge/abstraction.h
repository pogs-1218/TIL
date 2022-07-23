#ifndef BRIDGE_ABSTRACTION_H_
#define BRIDGE_ABSTRACTION_H_

class Abstraction {
 public:
  virtual ~Abstraction() = default;
  virtual void Operation() = 0;
};

#endif
