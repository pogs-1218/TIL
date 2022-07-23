#include "handler.h"

Handler::Handler(Handler* handler, Topic topic)
    : next_handler_{handler}, topic_{topic} {}

void Handler::HandleRequest() {
  if (next_handler_) {
    next_handler_->HandleRequest();
  }
}

bool Handler::CanHandle() { return topic_ != Topic::None; }