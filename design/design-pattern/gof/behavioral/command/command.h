#ifndef COMMAND_COMMAND_H_
#define COMMAND_COMMAND_H_

// invoker가 호출할 command interface
class Command {
 public:
  virtual ~Command() = default;
  virtual void Execute() = 0;
};

#endif