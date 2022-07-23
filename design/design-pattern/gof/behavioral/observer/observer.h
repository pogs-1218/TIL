#ifndef OBSERVER_OBSERVER_H_
#define OBSERVER_OBSERVER_H_

class Observer {
 public:
  virtual ~Observer() = default;
  // Push model.
  virtual void Update(int state) = 0;
};

#endif