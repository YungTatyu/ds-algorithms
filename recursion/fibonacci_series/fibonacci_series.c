#include <stdio.h>

/**
 * time complexity O(2^n)
 * excessive recursion, which means it calles itself multiple times for same
 * params
 */
int fibonacci_series(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci_series(n - 2) + fibonacci_series(n - 1);
}

/**
 * time complexity O(n)
 * using memorization
 *
 */
int optimized_fibonacci_series(int n) {
  static int memory[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  if (n <= 1) {
    memory[n] = n;
    return n;
  }

  if (memory[n] != -1) {
    return memory[n];
  }
  if (memory[n - 2] == -1) {
    memory[n - 2] = optimized_fibonacci_series(n - 2);
  }
  if (memory[n - 1] == -1) {
    memory[n - 1] = optimized_fibonacci_series(n - 1);
  }
  memory[n] = memory[n - 1] + memory[n - 2];
  return memory[n];
}

/**
 * time complexity O(n)
 */
int fibonacci_series_with_loop(int n) {
  if (n <= 1) {
    return n;
  }
  int t1 = 0;
  int t2 = 1;
  for (int i = 2; i < n; ++i) {
    int sum = t1 + t2;
    t1 = t2;
    t2 = sum;
  }
  return t1 + t2;
}

int main(int argc, char *argv[]) {
  int num = 5;
  printf("%d\n", fibonacci_series(num));
  printf("%d\n", fibonacci_series_with_loop(num));
  printf("%d\n", optimized_fibonacci_series(num));
  return 0;
}
