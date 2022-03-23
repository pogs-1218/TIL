#ifndef ACTIVATION_LIST_H_
#define ACTIVATION_LIST_H_

#include <condition_variable>
#include <cstdint>
#include <mutex>

#include "method_request.h"

class TimeOut;

class ActivationList {
 public:
  enum { INFINITE = -1 };
  // iterator

  ActivationList(std::size_t high_water_mark);

  void Insert(MethodRequest* method_request, TimeOut* timeout = nullptr);
  void Remove(MethodRequest* method_request, TimeOut* timeout = nullptr);

  class Iterator {
   public:
    Iterator& Begin();
    Iterator& End();
    void operator++();
  };

 private:
  // Synchronization mechanisms.
  std::mutex mtx_;

  // Queue implementation.
  std::list<MethodRequest*> request_queue_;
};

#endif