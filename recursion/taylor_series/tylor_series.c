

#include <stdio.h>

/**
 *
 * e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!
 *
 */
double taylor_series(int x, int n) {
  static double power_x = 1;
  static double fractoral_n = 1;
  if (n == 0) {
    return 1;
  }
  double re = taylor_series(x, n - 1);
  power_x *= x;
  fractoral_n *= n;
  return re + power_x / fractoral_n;
}

/**
 *
 * time complexity O(n)
 */
double optimized_taylor_series(int x, int n) {
  static double re = 1.0;
  if (n == 0) {
    return re;
  }
  re = 1 + (double)x / (double)n * re;
  return optimized_taylor_series(x, n - 1);
}

int main(int argc, char *argv[]) {

  printf("%lf\n", taylor_series(3, 10));
  printf("%lf\n", optimized_taylor_series(3, 10));
  return 0;
}
