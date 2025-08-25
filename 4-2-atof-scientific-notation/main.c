#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]);

int main() {
  char s[] = "123e6";

  printf("%f\n", atof(s));

  return 0;
}

double atof(char s[]) {
  double val, power;
  int i, sign, exponent_sign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    int exponent;

    i++;

    exponent_sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
      i++;
    }

    for (exponent = 0; isdigit(s[i]); i++) {
      exponent = 10 * exponent + (s[i] - '0');
    }

    exponent *= sign;

    val *= pow(10, exponent);
  }

  return sign * val / power;
}
