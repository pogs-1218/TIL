#ifndef STATE_STATE_H_
#define STATE_STATE_H_

#include <string>

#include "connection.h"

class State {
 public:
  virtual ~State() = default;
  virtual void Open(Connection* connection) = 0;
  virtual void Transmit(Connection* connection, const std::string& data) = 0;
  virtual void Close(Connection* connection) = 0;

 protected:
  void ChangeState(Connection* connection, State* state) {
    connection->set_state(state);
  }
};

#endif