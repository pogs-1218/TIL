#include "subject1.h"

void Subject1::Notify() {
  for (auto& observer : observers_) {
    observer->Update(state_);
  }
}