#ifndef STATE_CONNECTED_STATE_H_
#define STATE_CONNECTED_STATE_H_

#include "state.h"

class ConnectedState : public State {
 public:
  static ConnectedState* Instance();
  ~ConnectedState() override;

  void Open(Connection* connection) override;
  void Transmit(Connection* connection, const std::string& data) override;
  void Close(Connection* connection) override;

 private:
  ConnectedState() = default;
  static ConnectedState* instance_;
};

#endif