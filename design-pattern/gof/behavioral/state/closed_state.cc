#include "closed_state.h"

#include <iostream>

#include "connected_state.h"

ClosedState* ClosedState::instance_ = nullptr;

ClosedState* ClosedState::Instance() {
  if (instance_ == nullptr) {
    instance_ = new ClosedState;
  }
  return instance_;
}

void ClosedState::Open(Connection* connection) {
  ChangeState(connection, ConnectedState::Instance());
  std::cout << "Change State[Closed->Connected]" << std::endl;
}

void ClosedState::Transmit(Connection* connection, const std::string& data) {
  std::cout << "Can't transmit data.(connection is closed)" << std::endl;
}

void ClosedState::Close(Connection* connection) {
  std::cout << "Can't close. (connection is already closed)" << std::endl;
}