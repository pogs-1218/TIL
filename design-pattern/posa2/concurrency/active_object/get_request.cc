#include "get_request.h"

GetRequest::GetRequest(MQServant* rep, const MessageFuture& f)
    : servant_{rep}, result_{f} {}

GetRequest::~GetRequest() {}

bool GetRequest::can_run() const { return !servant_->empty(); }

void GetRequest::call() {
  // result_ = servant_->Get();
}
