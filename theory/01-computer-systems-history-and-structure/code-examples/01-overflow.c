#include <stdio.h>

int main() {
  char read = 203; // Implicit type conversion from int to char (overflow)

  // Result of comparison between -53 and 203 is always false
  printf("%d\n", read == 203);

  // Address of the variable (in hexadecimal)
  printf("%p\n", &read);
  return 0;
}
