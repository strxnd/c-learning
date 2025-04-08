#include <stdio.h>

int main() {
  double width;
  double height;
  double area;
  double perimeter;

  printf("Enter width of rectangle: ");
  scanf("%lf", &width);

  printf("Enter height of rectangle: ");
  scanf("%lf", &height);

  area = width * height;
  perimeter = 2 * (width + height);

  printf("The rectangle has an area of %lf and a perimeter of %lf.\n", area, perimeter);

  return 0;
}
