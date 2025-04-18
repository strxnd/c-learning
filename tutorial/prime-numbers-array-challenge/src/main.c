#include <stdio.h>

int main() {
  int primeNumbers[100];
  int count = 0;

  for (int i = 3; i <= 100; i++) {
    int isPrime = 1;

    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      primeNumbers[count] = i;
      count++;
    }
  }

  for (int i = 0; i < count; i++) {
    printf("%d", primeNumbers[i]);
    if (i < count - 1) {
      printf(", ");
    }
  }

  return 0;
}
