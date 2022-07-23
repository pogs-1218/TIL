#ifndef MQ_SCHEDULER_H_
#define MQ_SCHEDULER_H_

#include <cstdint>
#include <thread>

#include "activation_list.h"
#include "method_request.h"

class MQScheduler {
 public:
  MQScheduler(std::size_t high_water_mark);
  ~MQScheduler();

  void Insert(MethodRequest* method_request);

  virtual void Dispatch();

 private:
  static void* svc_run(void* arg);

  ActivationList act_list_;
  std::thread* thread_;
};

#endif