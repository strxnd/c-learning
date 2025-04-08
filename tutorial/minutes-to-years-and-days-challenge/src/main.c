#include <stdio.h>

int main() {
  double minutes;
  double minutesInYear = 525600;
  double minutesInDay = 1440;
  double years;
  double days;

  printf("Enter minutes: ");
  scanf("%lf", &minutes);

  years = minutes / minutesInYear;
  days = minutes / minutesInDay;
  
  printf("%lf minutes is %lf years.\n", minutes, years);
  printf("%lf minutes is %lf days.\n", minutes, days);
  
  return 0 ;
}
