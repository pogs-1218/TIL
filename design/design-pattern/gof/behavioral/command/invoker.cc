#include "invoker.h"

Invoker::Invoker(Command* command) : command_(command) {}

void Invoker::Operation() {
  if (command_) {
    command_->Execute();
  }
}