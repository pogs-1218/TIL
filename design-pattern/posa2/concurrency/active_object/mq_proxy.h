#ifndef MQ_PROXY_H_
#define MQ_PROXY_H_

#include <cstdint>

#include "message.h"
#include "message_future.h"
#include "mq_scheduler.h"
#include "mq_servant.h"

class MQProxy {
 public:
  enum { MQ_MAX_SIZE = 10 };

  MQProxy(std::size_t size = MQ_MAX_SIZE);

  void Put(const Message& msg);
  MessageFuture Get();

  // empty? full?

 private:
  MQServant servant_;
  MQScheduler scheduler_;
};

#endif