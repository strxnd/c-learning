#include <stdio.h>

int main() {
  printf("Byte size of type int: %zd\n", sizeof(int));
  printf("Byte size of type char: %zd\n", sizeof(char));
  printf("Byte size of type long: %zd\n", sizeof(long));
  printf("Byte size of type long long: %zd\n", sizeof(long long));
  printf("Byte size of type double: %zd\n", sizeof(double));
  printf("Byte size of type long double: %zd\n", sizeof(long double));

  return 0;
}
