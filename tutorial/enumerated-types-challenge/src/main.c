#include <stdio.h>

int main() {
  enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };

  enum Company company1 = XEROX;
  enum Company company2 = GOOGLE;
  enum Company company3 = EBAY;

  printf("%d", company1);
  printf("%d", company2);
  printf("%d", company3);

  return 0;
}
