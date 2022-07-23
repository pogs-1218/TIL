#ifndef MQ_SERVANT_H_
#define MQ_SERVANT_H_

#include <cstdint>
#include <list>

#include "message.h"

class MQServant {
 public:
  MQServant(std::size_t mq_size);
  ~MQServant();

  void Put(const Message& msg);
  Message Get();

  bool empty() const;
  bool full() const;

 private:
  // internal queue. circular array or linked linst. does not use any internal
  // synchronization mechanism.
  std::list<Message> message_list_;
};

#endif