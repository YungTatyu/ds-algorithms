#include <stdio.h>

/**
 * time complexity O(n)
 * space complexity O(n)
 */
int power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  }
  return power(base, exponent - 1) * base;
}

/**
 * time complexity O(log n)
 * space complexity O(log n)
 * because function is calling itself with n/2 every time.
 */
int optimized_power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  }
  if (exponent % 2 == 0) {
    return optimized_power(base * base, exponent / 2);
  } else {
    return base * optimized_power(base * base, (exponent - 1) / 2);
  }
}
int main(int argc, char *argv[]) {
  printf("%d\n", power(2, 9));
  printf("%d\n", optimized_power(2, 9));
  printf("%d\n", power(9, 3));
  printf("%d\n", optimized_power(9, 3));
  return 0;
}
