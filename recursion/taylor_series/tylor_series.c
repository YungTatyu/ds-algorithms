

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

int main(int argc, char *argv[]) {

  printf("%lf", taylor_series(3, 10));
  return 0;
}
