#include <stdio.h>

int fibonacci_series(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci_series(n - 2) + fibonacci_series(n - 1);
}

int fibonacci_series_with_loop(int n) {
  if (n <= 1) {
    return n;
  }
  int t1 = 0;
  int t2 = 1;
  for (int i = 2; i < n; ++i) {
    if (i % 2 == 0) {
      t1 += t2;
    } else {
      t2 += t1;
    }
  }
  return t1 + t2;
}

int main(int argc, char *argv[]) {
  printf("%d\n", fibonacci_series(5));
  printf("%d\n", fibonacci_series_with_loop(5));
  return 0;
}
