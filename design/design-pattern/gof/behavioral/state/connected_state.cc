#include "connected_state.h"

#include <iostream>

#include "closed_state.h"

ConnectedState* ConnectedState::instance_ = nullptr;

ConnectedState* ConnectedState::Instance() {
  if (instance_ == nullptr) {
    instance_ = new ConnectedState;
  }
  return instance_;
}

void ConnectedState::Open(Connection* connection) {
  std::cout << "Already connected" << std::endl;
}

void ConnectedState::Transmit(Connection* connection, const std::string& data) {
  std::cout << data << std::endl;
}

void ConnectedState::Close(Connection* connection) {
  ChangeState(connection, ClosedState::Instance());
  std::cout << "Change State[Connected->Closed]" << std::endl;
}
