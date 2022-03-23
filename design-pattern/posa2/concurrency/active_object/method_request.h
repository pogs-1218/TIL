#ifndef METHOD_REQUEST_H_
#define METHOD_REQUEST_H_

class MethodRequest {
 public:
  virtual ~MethodRequest() = default;
  virtual bool can_run() const = 0;
  virtual void call() = 0;
};

#endif