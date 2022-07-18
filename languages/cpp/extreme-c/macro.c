#include <stdio.h>
#include <string.h>

#define TEST_MACRO\
  int i = 0;\
  i = 15;

int main(){
  TEST_MACRO

    int j = 12;
    return 0;
}
