// Should know about the memory layout

#include <stdio.h>

// memory alignment
// memory -> CPU : slow and read word bytes.
// The word is atomic unit used by the CPU to read from and write to the memory.
// 64bit: word = 4bytes. (architecture dependant)

// sample_t has
// | word1(4bytes) | word2(4bytes) |
// word1
// |first(1byte)|second(1byte)|third(1byte)|padding(1byte)| -> compiler add a
// padding.

// Don't allow alignment.
// struct __attribute__((__packed__)) sample_t {
struct sample_t {
  char first;
  char second;
  char third;
  short fourth;
};

typedef struct {
  int x;
  int y;
} point_t;

typedef struct {
  point_t center;
  int radius;
} circle_t;

typedef struct {
  point_t start;
  point_t end;
} line_t;

void print_size(struct sample_t *var) {
  printf("Size: %lu bytes\n", sizeof(*var));
}

void print_bytes(struct sample_t *var) {
  unsigned char *ptr = (unsigned char *)var;

  for (int i = 0; i < sizeof(*var); i++, ptr++) {
    printf("%d ", (unsigned int)*ptr);
  }
  printf("\n");
}

int main() {
  struct sample_t var;
  var.first = 'A';
  var.second = 'B';
  var.third = 'C';
  var.fourth = 257;

  print_size(&var);

  print_bytes(&var);

  return 0;
}
