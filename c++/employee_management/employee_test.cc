#include "employee.h"

#include <iostream>

int main() {
  std::cout << "Testing the Employee class." << std::endl;
  records::Employee emp{"Jane", "Doe"};
  emp.set_first_name("John");
  emp.set_last_name("Doe");
  emp.set_employee_number(71);
  emp.set_salary(50'000);
  emp.Promote();
  emp.Promote(50);
  emp.Hire();
  emp.Display();

  return 0;
}