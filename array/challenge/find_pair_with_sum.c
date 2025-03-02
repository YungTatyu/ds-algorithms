#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int max(const unsigned int *arr, size_t size) {
  unsigned int max = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void find_pair_with_sum(const unsigned int *arr, size_t size,
                        unsigned int sum) {
  size_t h_size = max(arr, size) + 1;
  unsigned int *h = (unsigned int *)calloc(h_size, sizeof(unsigned int));
  if (h == NULL) {
    return;
  }
  for (size_t i = 0; i < size; ++i) {
    if (sum - arr[i] >= 0 && h[sum - arr[i]] > 0) {
      printf("%u + %u = %d\n", arr[i], sum - arr[i], sum);
    }
    ++h[arr[i]];
  }
  free(h);
}

void find_pair_with_sum_sorted_array(const int *arr, size_t size, int sum) {
  size_t li = 0, ri = size - 1;
  while (li < ri) {
    if (arr[li] + arr[ri] == sum) {
      printf("%d + %d = %d\n", arr[li], arr[ri], sum);
      ++li;
      --ri;
    } else if (arr[li] + arr[ri] > sum) {
      --ri;
    } else {
      ++li;
    }
  }
}

int main(int argc, char *argv[]) {

  int arr[] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 14};
  find_pair_with_sum_sorted_array(arr, sizeof(arr) / sizeof(int), 12);
  return 0;
}
