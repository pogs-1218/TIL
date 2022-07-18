#ifndef OBSERVER_SUBJECT_H_
#define OBSERVER_SUBJECT_H_

#include <list>

#include "observer.h"

class Subject {
 public:
  virtual ~Subject() = default;

  virtual void Attach(Observer* observer);
  virtual void Detach(Observer* observer);
  virtual void Notify() = 0;

 protected:
  Subject() = default;
  std::list<Observer*> observers_;
};

#endif