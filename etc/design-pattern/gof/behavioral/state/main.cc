#include "connection.h"

int main() {
  Connection connection;

  connection.Open();
  connection.Transmit("hello world");
  connection.Close();

  return 0;
}