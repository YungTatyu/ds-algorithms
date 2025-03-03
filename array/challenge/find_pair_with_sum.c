#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void find_max_min(const int *arr, size_t size) {
  int min, max;
  min = max = arr[0];
  for (size_t i = 1; i < size; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    } else {
      max = arr[i];
    }
  }
  printf("min: %d  max: %d\n", min, max);
}

void find_pair_with_sum_including_negative(const int *arr, size_t size,
                                           int sum) {
  int min = arr[0];
  int max = 0; // only use this to calculate hash table size so 0 is fine
  for (size_t i = 1; i < size; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    } else {
      max = arr[i];
    }
  }
  int *copy = (int *)calloc(size, sizeof(int));
  if (copy == NULL) {
    return;
  }
  memcpy(copy, arr, size * sizeof(int));
  int updated_sum = sum;
  if (min < 0) {
    min = min * -1; // needs extra memories if min is negative
    // because sum is consist of two elements which are added by min
    updated_sum += 2 * min;
    for (size_t i = 0; i < size; ++i) {
      copy[i] += min;
    }
  } else {
    min = 0;
  }
  size_t h_size = min + max + 1;
  int *h = (int *)calloc(h_size, sizeof(int));
  if (h == NULL) {
    free(copy);
    return;
  }

  for (size_t i = 0; i < size; ++i) {
    if (updated_sum - copy[i] >= 0 && h[updated_sum - copy[i]] > 0) {
      printf("%d + %d = %d\n", arr[i], sum - arr[i], sum);
    }
    ++h[arr[i]];
  }
  free(h);
  free(copy);
}

int main(int argc, char *argv[]) {

  int arr[] = {1, -3, 4, 5, 6, -7, 7, -8, 9, -10, 14};
  find_pair_with_sum_including_negative(arr, sizeof(arr) / sizeof(int), 1);
  return 0;
}
