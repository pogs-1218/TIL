#include "database.h"

namespace records {
Employee& Database::AddEmployee(const std::string& first_name,
                                const std::string& last_name) {
  Employee new_employee{first_name, last_name};
  new_employee.set_employee_number(next_employee_number_++);
  new_employee.Hire();
  employees_.push_back(new_employee);
  return employees_.back();
}

Employee& Database::employee(int employee_number) {
  for (auto& employee : employees_) {
    if (employee.employee_number() == employee_number) {
      return employee;
    }
  }
}

void Database::DisplayAll() const {
  for (const auto& employee : employees_) {
    employee.Display();
  }
}

void Database::DisplayCurrent() const {
  for (const auto& employee : employees_) {
    if (employee.is_hired()) employee.Display();
  }
}

}  // namespace records