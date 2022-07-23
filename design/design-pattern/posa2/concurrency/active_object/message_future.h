#ifndef MESSAGE_FUTURE_H_
#define MESSAGE_FUTURE_H_

#include "message.h"

class MessageFuture {
 public:
  MessageFuture();
  MessageFuture(const Message& msg);

  MessageFuture(const MessageFuture& f);
  void operator=(const MessageFuture& f);

  Message Result(/*timeout*/) const;

 private:
  // ref-counted.
  class Impl;
  Impl* impl_;
};

#endif