#include "mq_scheduler.h"

MQScheduler::MQScheduler(std::size_t high_water_mark)
    : act_list_{high_water_mark} {
  thread_ = new std::thread{&svc_run, this};
}

MQScheduler::~MQScheduler() {}

void MQScheduler::Insert(MethodRequest* method_request) {
  act_list_.Insert(method_request);
}

void MQScheduler::Dispatch() {
  for (;;) {
    ActivationList::Iterator iter;
    for (;;) {
      // check request can run

      // call request

      // delete request
    }
  }
}

void* svc_run(void* arg) {
  auto scheduler = static_cast<MQScheduler*>(arg);
  scheduler->Dispatch();
}
