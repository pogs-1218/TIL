#ifndef CONSUMER_HANDLER_H_
#define CONSUMER_HANDLER_H_

#include <thread>

#include "message.h"
#include "mq_proxy.h"

class ConsumerHandler {
 public:
  ConsumerHandler();
  void Put(const Message& msg);

 private:
  // thread entry point
  static void* svc_run(void* arg);

  MQProxy msq_queue_;
  // sock stream connection
  std::thread* thread_;
};

#endif