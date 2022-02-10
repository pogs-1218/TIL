#ifndef CHAIN_RECEIVER_FINAL_H_
#define CHAIN_RECEIVER_FINAL_H_

#include "handler.h"

class ReceiverFinal : public Handler {
 public:
  ~ReceiverFinal() override = default;
  void HandleRequest() override;
};

#endif