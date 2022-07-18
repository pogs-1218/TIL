#ifndef BODY_H_
#define BODY_H_

#include <iostream>
#include <string>

class RefBody {
 public:
  void Service() { std::cout << name_ << std::endl; }

 private:
  friend class Handle;
  RefBody(const std::string& name) : name_{name} {};
  ~RefBody() = default;

  int ref_count_;
  std::string name_;
};

class Body {
 public:
  Body(const std::string& name) : name_{name} {};
  ~Body() = default;

  void Service() { std::cout << name_ << std::endl; }

  std::string name_;
};

#endif