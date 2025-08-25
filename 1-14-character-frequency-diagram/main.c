#include <stdio.h>

int main() {
  int c;
  int frequency[256] = {0};

  while ((c = getchar()) != EOF) {
    frequency[c]++;
  }

  printf("\n");

  for (int i = 0; i < 256; i++) {
    if (frequency[i] > 0) {
      printf("%c: ", i);
      for (int j = 0; j < frequency[i]; j++) {
        printf("*");
      }
      printf("\n");
    }
  }
}
