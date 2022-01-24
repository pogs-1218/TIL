#include <iostream>
#include "composite.h"
#include "leaf.h"

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
  
  return 0;
}
