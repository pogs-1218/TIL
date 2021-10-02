#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

namespace records {

const int kDefaultStartingSalary{30'000};
const int kDefaultRaiseAndDemeritAmount{1'000};

class Employee {
 public:
  Employee(const std::string& first_name, const std::string& last_name);

  void Promote(int raise_amount = kDefaultRaiseAndDemeritAmount);
  void Demote(int demerit_amout = kDefaultRaiseAndDemeritAmount);
  void Hire();
  void Fire();
  void Display() const;

  void set_first_name(const std::string& first_name);
  const std::string& first_name() const;

  void set_last_name(const std::string& last_name);
  const std::string& last_name() const;

  void set_employee_number(int number);
  int employee_number() const;

  void set_salary(int new_salary);
  int salary() const;

  bool is_hired() const;

 private:
  std::string first_name_;
  std::string last_name_;
  int employee_number_{-1};
  int salary_{kDefaultStartingSalary};
  bool is_hired_{false};
};

}  // namespace records

#endif
