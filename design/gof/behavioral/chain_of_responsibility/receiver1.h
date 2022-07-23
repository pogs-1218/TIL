#ifndef CHAIN_RECEIVER1_H_
#define CHAIN_RECEIVER1_H_

#include "handler.h"

class Receiver1 : public Handler {
 public:
  Receiver1(Handler* handler, Topic topic = Topic::None);
  ~Receiver1() override = default;
  void HandleRequest() override;
};

#endif