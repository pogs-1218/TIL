#include "consumer_handler.h"

ConsumerHandler::ConsumerHandler() { thread_ = new std::thread{svc_run, this}; }

void ConsumerHandler::Put(const Message& msg) { msq_queue_.Put(msg); }

void* ConsumerHandler::svc_run(void* arg) {
  auto handler = static_cast<ConsumerHandler*>(arg);
  // Block until message is available
  for (;;) {
    auto msg = handler->msq_queue_.Get().Result();

    // Transmit Message to the consumer over the TCP connection
    // handler->connection_.send(msg, msg.length());
  }
}