#include "command1.h"

Command1::Command1(Receiver* receiver) : receiver_(receiver) {}

Command1::~Command1() = default;

void Command1::Execute() { receiver_->Action(); }