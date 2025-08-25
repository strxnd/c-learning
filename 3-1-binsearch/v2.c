#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int x = 499;
  int v[500];
  for (int i = 0; i < 500; i++) {
    v[i] = i + 1;
  }
  int n = 500;

  printf("Index of 2: %d\n", binsearch(x, v, n));
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x <= v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (low < n && v[low] == x) {
    return low;
  } else {
    return -1;
  }
}
