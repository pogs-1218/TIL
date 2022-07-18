#ifndef CHAIN_HANDLER_H_
#define CHAIN_HANDLER_H_

enum class Topic { Hi, Bye, Easy, None };

class Handler {
 public:
  Handler(Handler* handler = nullptr, Topic topic = Topic::None);
  virtual ~Handler() = default;

  virtual void HandleRequest();
  virtual bool CanHandle();

 protected:
  Handler* next_handler_;
  Topic topic_;
};

#endif