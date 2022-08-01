#include <stdio.h>

void func(int *a) {
  int b = 5;
  *a = 3;

  a = &b;
}

int sum(int a, int b) {
  return a + b;  
}

int subtract(int a, int b){
  return a - b;
}

typedef int (*func_ptr)(int, int);

int main() {
  int x = 10;
  int *xptr = &x;

  printf("before x: %d\n", x);
  printf("before xptr: %p\n", xptr);

  func(xptr);

  printf("after x: %d\n", x);
  printf("after xptr: %p\n", xptr);

  func_ptr fptr = NULL;

  fptr = &sum;
  int result = fptr(5, 4);
  printf("sum: %d\n", result);

  fptr = &subtract;
  result = fptr(5, 4);
  printf("sub: %d\n", result);

  return 0;
}
