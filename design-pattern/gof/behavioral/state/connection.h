#ifndef STATE_CONNECTION_H_
#define STATE_CONNECTION_H_

class State;

class Connection {
 public:
  void Open();
  void Transmit();
  void Close();

 private:
  friend class State;
  void set_state(State* state);

  State* state_;
};

#endif