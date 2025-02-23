
/*
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
#include <stdio.h>
int combinatin(int n, int r) {
  if (r == 0 || r == n) {
    return 1;
  }
  return combinatin(n - 1, r - 1) + combinatin(n - 1, r);
}

int main(int argc, char *argv[]) {
  int num = 3;
  printf("%d\n", combinatin(3, 2));
  return 0;
}
