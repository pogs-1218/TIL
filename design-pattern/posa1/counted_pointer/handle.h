#ifndef HANDLE_H_
#define HANDLE_H_

#include "body.h"

class Handle {
 public:
  Handle(const std::string& param);
  Handle(const Handle& other);
  Handle& operator=(const Handle& other);

  ~Handle();

  RefBody* operator->() { return body_; }

 private:
  RefBody* body_;
};

#include "counting_body.h"

namespace v2 {
class Handle {
 public:
  Handle(const std::string& param);
  Handle(const Handle& other);
  Handle& operator=(const Handle& other);
  ~Handle();

 private:
  CountingBody* counting_body_;
};
}  // namespace v2

namespace v3 {
template <typename T>
class Handle {
 public:
  Handle();
  Handle(const T& other);
  Handle& operator=(const T& other);

  ~Handle();

 private:
  int ref_count_;
  T* body_;
};
}  // namespace v3

#endif