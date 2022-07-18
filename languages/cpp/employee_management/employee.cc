#include "employee.h"

#include <iostream>

namespace records {

Employee::Employee(const std::string& first_name, const std::string& last_name)
    : first_name_{first_name}, last_name_{last_name} {}

void Employee::Promote(int raise_amount) {
  set_salary(salary() + raise_amount);
}

void Employee::Demote(int demerit_amount) {
  set_salary(salary() - demerit_amount);
}

void Employee::Hire() { is_hired_ = true; }

void Employee::Fire() { is_hired_ = false; }

void Employee::Display() const {
  std::cout << "Employee: " << last_name() << ", " << first_name() << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << (is_hired() ? "Current Employee" : "Former Employee")
            << std::endl;
  std::cout << "Employee number: " << employee_number() << std::endl;
  std::cout << "Salary: $" << salary() << std::endl;
  std::cout << std::endl;
}

void Employee::set_first_name(const std::string& first_name) {
  first_name_ = first_name;
}

const std::string& Employee::first_name() const { return first_name_; }

void Employee::set_last_name(const std::string& last_name) {
  last_name_ = last_name;
}

const std::string& Employee::last_name() const { return last_name_; }

void Employee::set_employee_number(int number) { employee_number_ = number; }

int Employee::employee_number() const { return employee_number_; }

void Employee::set_salary(int new_salary) { salary_ = new_salary; }

int Employee::salary() const { return salary_; }

bool Employee::is_hired() const { return is_hired_; }

}  // namespace records
