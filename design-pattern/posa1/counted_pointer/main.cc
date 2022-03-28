#include <iostream>

#include "handle.h"

int main() {
  Handle h1{"first name"};
  do {
    Handle h2 = h1;
    h2->Service();
  } while (0);
  h1->Service();

  v2::Handle v2h1{"first name"};

  return 0;
}