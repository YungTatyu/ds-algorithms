
#include <stdio.h>

/**
 * Pascal's Triangle:
 *
 *        1
 *       1 1
 *      1 2 1
 *     1 3 3 1
 *    1 4 6 4 1
 *   1 5 10 10 5 1
 *
 * nCr = (n-1)C(r-1) + (n-1)Cr
 *
 * 各行の要素は、直上の2つの数の和になっている。
 * 例: 6 = 3 + 3, 10 = 4 + 6
 */
int combinatin(int n, int r) {
  if (r == 0 || r == n) {
    return 1;
  }
  return combinatin(n - 1, r - 1) + combinatin(n - 1, r);
}

int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return fact(n - 1) * n;
}

/**
 * Combination formula (nCr):
 *
 *          n!
 * nCr = ------------
 *        r! (n-r)!
 *
 * Example:
 *   5C2 = 5! / (2! * (5-2)!)
 *        = (5 × 4 × 3 × 2 × 1) / ((2 × 1) × (3 × 2 × 1))
 *        = 10
 */
int combination_with_loop(int n, int r) {
  int num = fact(n);
  int den = fact(r) * fact(n - r);
  return num / den;
}

int main(int argc, char *argv[]) {
  int num = 3;
  printf("%d\n", combination_with_loop(3, 2));
  printf("%d\n", combinatin(3, 2));
  return 0;
}
