#include "observer1.h"

Observer1::Observer1(Subject1& subject) : subject_{subject} {
  subject_.Attach(this);
}

Observer1::~Observer1() { subject_.Detach(this); }

void Observer1::Update(int state) { subject_.set_state(state); }