#include "receiver1.h"
#include "receiver_final.h"

int main() {
  auto handler{new Receiver1{new ReceiverFinal, Topic::Hi}};
  handler->HandleRequest();

  auto final_handler{new Receiver1{new ReceiverFinal, Topic::None}};
  final_handler->HandleRequest();

  return 0;
}