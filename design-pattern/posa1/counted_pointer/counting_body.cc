#include "counting_body.h"

CountingBody::CountingBody(Body* body) : body_{body} {}

CountingBody::~CountingBody() {
  delete body_;
  body_ = nullptr;
}