#include "command1.h"
#include "invoker.h"

int main() {
  auto invoker = new Invoker(new Command1(new Receiver));
  invoker->Operation();

  return 0;
}