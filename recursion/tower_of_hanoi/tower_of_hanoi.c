
#include <stdio.h>

/**
 * time complexity O(2^n)
 */
void toh(int n, int from, int using, int to) {
  if (n <= 0) {
    return;
  }
  toh(n - 1, from, to, using);
  printf("from %d to %d\n", from, to);
  toh(n - 1, using, from, to);
}

int main(int argc, char *argv[]) {
  toh(1, 1, 2, 3);
  printf("\n");
  toh(2, 1, 2, 3);
  printf("\n");
  toh(3, 1, 2, 3);
  printf("\n");
  toh(5, 1, 2, 3);
  return 0;
}
