#ifndef BRIDGE_IMPLEMENTOR_H_
#define BRIDGE_IMPLEMENTOR_H_

class Implementor {
 public:
  virtual ~Implementor() = default;
  virtual void Operation() = 0;
};

#endif
