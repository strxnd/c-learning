#include <stdio.h>

int main() {
  double num1, num2;
  char operator;

  printf("Enter number 1: ");
  if (scanf("%lf", &num1) != 1) {
    printf("Invalid input for number 1.\n");
    return 1;
  }

  printf("Enter number 2: ");
  if (scanf("%lf", &num2) != 1) {
    printf("Invalid input for number 2.\n");
    return 1;
  }

  printf("Enter operator (+,*,-,/): ");
  if (scanf(" %c", &operator) != 1) {
    printf("Invalid input for operator.\n");
    return 1;
  }

  printf("\n");

  if (operator== '+') {
    printf("Result: %f\n", num1 + num2);
  } else if (operator== '-') {
    printf("Result: %f\n", num1 - num2);
  } else if (operator== '*') {
    printf("Result: %f\n", num1 * num2);
  } else if (operator== '/') {
    if (num2 != 0) {
      printf("Result: %f\n", num1 / num2);
    } else {
      printf("Error: Division by zero is not allowed.\n");
      return 1;
    }
  } else {
    printf("Error: Invalid operator.\n");
    return 1;
  }

  return 0;
}
