#ifndef COMMAND_COMMAND1_H_
#define COMMAND_COMMAND1_H_

#include "command.h"
#include "receiver.h"

class Command1 : public Command {
 public:
  explicit Command1(Receiver* receiver);
  ~Command1() override;

  void Execute() override;

 private:
  Receiver* receiver_;
};

#endif