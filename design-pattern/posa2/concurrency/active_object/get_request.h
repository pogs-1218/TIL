#ifndef GET_REQUEST_H_
#define GET_REQUEST_H_

#include "message_future.h"
#include "method_request.h"
#include "mq_servant.h"

class GetRequest : public MethodRequest {
 public:
  GetRequest(MQServant* rep, const MessageFuture& f);
  ~GetRequest() override;

  bool can_run() const override;
  void call() override;

 private:
  MQServant* servant_;
  MessageFuture result_;
};

#endif