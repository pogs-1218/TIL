#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// struct tm : calendar time type
// time_t
//  --> can store an entire date and time.
// clock_t : is good for only for representing a time duration[K&R p.692]
// key : calendar time vs processor time
volatile double sink;

int main() {
  time_t epoch = 0;
  printf("%jd seconds since the epoch began\n", (intmax_t)(epoch));
  printf("%s", asctime(gmtime(&epoch)));

  clock_t start = clock();
  time_t start2 = time(NULL);
  //double sink = 0.0;
  for(size_t i = 0; i < 3141592; ++i)
    sink += sin(i);

  clock_t end = clock();
  time_t end2 = time(NULL);
  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("for loop take %f seconds to execute \n", cpu_time_used);
  printf("and %g seconds\n", difftime(end2, start2));

  time_t cur_time = time(NULL);
  
  return 0;
}
