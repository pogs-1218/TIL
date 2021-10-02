#include <iostream>
#include <string>

#include "database.h"
#include "employee.h"

int DisplayMenu();
int DoHire(records::Database& db);
int DoFire(records::Database& db);
int DoPromote(records::Database& db);

int main() {
  records::Database employee_db;
  bool done{false};
  while (!done) {
    int selection{DisplayMenu()};
    switch (selection) {
      case 0:
        done = true;
        break;
      case 1:
        DoHire(employee_db);
        break;
      case 2:
        DoFire(employee_db);
        break;
      case 3:
        DoPromote(employee_db);
        break;
      case 4:
        employee_db.DisplayAll();
        break;
      case 5:
        employee_db.DisplayCurrent();
        break;
      case 6:
        employee_db.DisplayFormer();
        break;
      default:
        std::cerr << "Unknown Command" << std::endl;
        break;
    }
  }
}

int DisplayMenu() {
  int selection;
  std::cout << std::endl;
  std::cout << "Employee Database" << std::endl;
  std::cout << "-----------------" << std::endl;
  std::cout << "1) Hire a new employee" << std::endl;
  std::cout << "2) Fire an employee" << std::endl;
  std::cout << "3) Promote an employee" << std::endl;
  std::cout << "4) List all employees" << std::endl;
  std::cout << "5) List all current employees" << std::endl;
  std::cout << "0) Quit" << std::endl;
  std::cout << std::endl;
  std::cout << "----> ";
  std::cin >> selection;
  return selection;
}

int DoHire(records::Database& db) {
  std::string first_name, last_name;

  std::cout << "First name? ";
  std::cin >> first_name;
  std::cout << "Last name? ";
  std::cin >> last_name;

  auto& employee = db.AddEmployee(first_name, last_name);
}

int DoFire(records::Database& db) {
  int employee_number;

  std::cout << "Employee numbr? ";
  std::cin >> employee_number;
  auto& employee = db.employee(employee_number);
  employee.Fire();
}

int DoPromote(records::Database& db) {
  int employee_number;
  std::cout << "Employee numbr? ";
  std::cin >> employee_number;

  int raise_amount;
  std::cout << "How much of a raise? ";
  std::cin >> raise_amount;

  auto& employee = db.employee(employee_number);
  employee.Promote(raise_amount);
}