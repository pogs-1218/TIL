#ifndef COMMAND_RECEIVER_H_
#define COMMAND_RECEIVER_H_

#include <iostream>

class Receiver {
 public:
  void Action() { std::cout << "Receiver's action" << std::endl; }
};

#endif