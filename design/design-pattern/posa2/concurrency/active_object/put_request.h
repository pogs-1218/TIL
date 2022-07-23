#ifndef PUT_REQUEST_H_
#define PUT_REQUEST_H_

#include "message_future.h"
#include "method_request.h"
#include "mq_servant.h"

class PutRequest : public MethodRequest {
 public:
  PutRequest(MQServant* servant, const Message& msg);
  ~PutRequest() override;

  bool can_run() const override;
  void call() override;

 private:
  MQServant* servant_;
  // MessageFuture result_;
};

#endif