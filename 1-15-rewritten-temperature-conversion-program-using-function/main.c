#include <stdio.h>

float fahr_to_celcius(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

int main() {
  float fahr, celsius;
  int lower = 0, upper = 300, step = 20;

  fahr = lower;

  printf("┌────────────┬────────────┐\n");
  printf("│ Fahrenheit │ Celsius    │\n");
  printf("├────────────┼────────────┤\n");

  while (fahr <= upper) {
    celsius = fahr_to_celcius(fahr);
    printf("│ %8.0f   │ %10.1f │\n", fahr, celsius);
    fahr += step;
  }

  printf("└────────────┴────────────┘\n");

  return 0;
}
