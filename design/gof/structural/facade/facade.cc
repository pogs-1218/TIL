#include "facade.h"
#include "class1.h"
#include "class2.h"

void Facade::Operation(){
  Class1 c1;
  Class2 c2;

  c1.Operation();
  c2.Operation();
}
