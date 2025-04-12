/* Following the rules below:
 * - Basic pay rate = $12/hr
 * - Overtime (in excess of 40 hours) = time and a half
 * - Tax rate:
 *   - 15% of the first $300
 *   - 20% of the next $150
 *   - 25% of the rest
 */

#include <stdio.h>

int main() {
  int hoursWorkedInWeek;
  int hourlyPay = 12;
  int grossPay;
  int netPay;

  printf("Enter number of hours worked per week: ");
  scanf("%d", &hoursWorkedInWeek);

  // Calculating and printing gross pay
  if (hoursWorkedInWeek <= 40) {
    grossPay = hoursWorkedInWeek * hourlyPay;

    printf("The gross pay is: $%d\n", grossPay);
  } else {
    int overtimeHoursWorked = hoursWorkedInWeek - 40;
    int overtimeHoursWeeklyPay = hourlyPay + hourlyPay * 0.5;
    int extraPay = overtimeHoursWorked * overtimeHoursWeeklyPay;
    int normalHoursWorked = 40;
    int normalHoursPay = normalHoursWorked * hourlyPay;
    grossPay = normalHoursPay + extraPay;

    printf("The gross pay is: $%d\n", grossPay);
  }

  // Calculating tax and printing net pay
  if (grossPay > 450) {
    int restOfMoney = grossPay - 450;
    int tax = (restOfMoney * 0.25) + (150 * 0.2) + (300 * 0.15);
    netPay = grossPay - tax;

    printf("The net pay is: $%d\n", netPay);
  } else if (grossPay > 300) {
    int next150 = grossPay - 300;
    int tax = (next150 * 0.2) + (300 * 0.15);
    netPay = grossPay - tax;

    printf("The net pay is: $%d\n", netPay);
  } else {
    int tax = grossPay * 0.15;
    netPay = grossPay - tax;

    printf("The net pay is: $%d\n", netPay);
  }

  return 0;
}
