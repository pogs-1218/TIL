#include "handle.h"

Handle::Handle(const std::string& param) : body_{new RefBody(param)} {
  body_->ref_count_ = 1;
}

Handle::Handle(const Handle& other) {
  body_ = other.body_;
  body_->ref_count_++;
}

Handle& Handle::operator=(const Handle& other) {
  if (this == &other) return *this;

  other.body_->ref_count_++;
  if (--body_->ref_count_ <= 0) delete body_;
  body_ = other.body_;
  return *this;
}

Handle ::~Handle() {
  if (--body_->ref_count_ <= 0) delete body_;
}

namespace v2 {
// Handle::Handle(const std::string& param)
//     : counting_body_{new CountingBody(param)} {}

// Handle::Handle(const Handle& other) {
//   other.counting_body_->IncrementRef();
//   counting_body_ = other.counting_body_;
// }

// Handle& Handle::operator=(const Handle& other) {
//   if (this == &other) return *this;

//   other.counting_body_->IncrementRef();

//   if (counting_body_->DecrementRef() <= 0) delete counting_body_;

//   counting_body_ = other.counting_body_;
//   return *this;
// }

// Handle ::~Handle() {
//   if (counting_body_->DecrementRef() <= 0) delete counting_body_;
// }
}  // namespace v2