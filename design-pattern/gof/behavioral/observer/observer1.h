#ifndef OBSERVER_OBSERVER1_H_
#define OBSERVER_OBSERVER1_H_

#include "observer.h"
#include "subject1.h"

class Observer1 : public Observer {
 public:
  Observer1(Subject1& subject);
  ~Observer1() override = default;
  void Update(int state) override;

 private:
  Subject1& subject_;
};

#endif