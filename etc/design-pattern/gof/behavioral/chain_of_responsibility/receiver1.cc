#include "receiver1.h"

#include <iostream>

Receiver1::Receiver1(Handler* handler, Topic topic) : Handler{handler, topic} {}

void Receiver1::HandleRequest() {
  if (CanHandle()) {
    std::cout << "Receiver1 can handle the request" << std::endl;
  } else {
    Handler::HandleRequest();
  }
}