#ifndef STATE_CONNECTION_H_
#define STATE_CONNECTION_H_

class State;

class Connection {
 public:
  Connection();
  ~Connection();

  void Open();
  void Transmit(const std::string& data);
  void Close();

 private:
  friend class State;
  void set_state(State* state);

  State* state_;
};

#endif