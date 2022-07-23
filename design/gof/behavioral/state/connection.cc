#include "connection.h"

#include "closed_state.h"

Connection::Connection() : state_{ClosedState::Instance()} {}

Connection::~Connection() { state_->Close(this); }

void Connection::Open() { state_->Open(this); }

void Connection::Transmit(const std::string& data) {
  state_->Transmit(this, data);
}

void Connection::Close() { state_->Close(this); }