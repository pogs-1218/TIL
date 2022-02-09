#ifndef STATE_CLOSED_STATE_H_
#define STATE_CLOSED_STATE_H_

#include "state.h"

class ClosedState : public State {
 public:
  static ClosedState* Instance();
  ~ClosedState() override;

  void Open(Connection* connection) override;
  void Transmit(Connection* connection, const std::string& data) override;
  void Close(Connection* connection) override;

 private:
  ClosedState() = default;
  static ClosedState* instance_;
};

#endif