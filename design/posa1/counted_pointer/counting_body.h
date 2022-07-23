#ifndef COUNTING_BODY_H_
#define COUNTING_BODY_H_

#include "body.h"

class CountingBody {
 public:
  CountingBody(Body* body);
  ~CountingBody();

  Body* operator->() { return body_; }

  int Ref() const { return ref_count_; }
  int IncrementRef() { return ++ref_count_; }
  int DecrementRef() { return --ref_count_; }

 private:
  int ref_count_{1};
  Body* body_;
};

#endif