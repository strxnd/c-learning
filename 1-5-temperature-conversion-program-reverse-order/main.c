#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower = 300, upper = 0, step = 20;

  celsius = lower;

  printf("┌─────────┬────────────┐\n");
  printf("│ Celcius │ Fahrenheit │\n");
  printf("├─────────┼────────────┤\n");

  while (celsius > upper) {
    fahr = (celsius * 9 / 5) + 32;
    printf("│ %7.0f │ %10.0f │\n", celsius, fahr);
    celsius -= step;
  }

  printf("└─────────┴────────────┘\n");

  return 0;
}
