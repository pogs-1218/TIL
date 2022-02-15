#ifndef OBSERVER_SUBJECT1_H_
#define OBSERVER_SUBJECT1_H_

#include "subject.h"

class Subject1 : public Subject {
 public:
  void Notify() override;

  void set_state(int state);
  void state();

 private:
  int state_;
};

#endif