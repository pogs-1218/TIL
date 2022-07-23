#include "mq_proxy.h"

#include "get_request.h"
#include "put_request.h"

MQProxy::MQProxy(std::size_t size) : servant_(size), scheduler_(size) {}

void MQProxy::Put(const Message& msg) {
  auto request = new PutRequest{&servant_, msg};
  scheduler_.Insert(request);
}

MessageFuture MQProxy::Get() {
  MessageFuture result;
  auto request = new GetRequest(&servant_, result);
  scheduler_.Insert(request);
  return result;
}
