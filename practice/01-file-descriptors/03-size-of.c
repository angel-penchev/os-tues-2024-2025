#include <stdio.h>

typedef struct {
  char data;
  unsigned char next_element_address;
} block;

int main(void) {
  printf("%ld\n", sizeof(block));
  return 0;
}
