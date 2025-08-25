#include <stdio.h>

int main() {
  int result;

  printf("Enter a character: ");
  result = getchar() != EOF;

  printf("\nExpression getchar() != EOF evaluates to: %d\n", result);
}
