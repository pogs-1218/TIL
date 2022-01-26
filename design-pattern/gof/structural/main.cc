#include <iostream>
#include "composite/composite.h"
#include "composite/leaf.h"

#include "bridge/abstraction1.h"
#include "bridge/implementor1.h"

#include "facade/facade.h"

int main(){
  // Build tree !
  auto comp1 { new Composite("comp1 ") };
  comp1->AddChild(new Leaf("leaf1 "));
  comp1->AddChild(new Leaf("leaf2 "));

  auto comp2{new Composite("comp 2 ")};
  comp2->AddChild(new Leaf("leaf 3 "));
  comp2->AddChild(comp1);
  comp2->AddChild(new Leaf("leaf 4 "));
  
  // Print
  std::cout << comp1->Operation() << std::endl;
  std::cout << comp2->Operation() << std::endl;

  Abstraction* abs = new Abstraction1{new Implementor1};
  abs->Operation();

  // We don't need to handle Class1 or Class2!
  // If not, class1.h and class2.h files also be added in this file. -> dependency increased
  Facade facade;
  facade.Operation();
  
  return 0;
}
