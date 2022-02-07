#ifndef COMMAND_INVOKER_H_
#define COMMAND_INVOKER_H_

#include "command.h"

class Invoker {
 public:
  explicit Invoker(Command* command);
  void Operation();

 private:
  Command* command_;
};

#endif