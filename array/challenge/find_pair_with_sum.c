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

int main(int argc, char *argv[]) {

  unsigned int arr[] = {1, 3, 7, 8, 9, 10, 0, 2};
  find_pair_with_sum(arr, sizeof(arr) / sizeof(unsigned int), 10);
  return 0;
}
