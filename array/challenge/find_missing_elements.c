#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void find_single_missing_element(const int *arr, int n) {
  int diff = arr[0];
  for (size_t i = 1; i < n; ++i) {
    if (arr[i] - i != diff) {
      printf("missing %zu\n", diff + i);
      break;
    }
  }
}

/**
 * find missing elements from sorted array
 */
void find_missing_elements(const int *arr, int n) {
  size_t i = 0;
  for (size_t v = arr[i]; v < arr[n - 1]; ++v) {
    if (v != arr[i]) {
      printf("missing %zu\n", v);
    } else {
      ++i;
    }
  }
}

void find_missing_elements_using_hashtable(const unsigned int *arr, int n) {
  size_t i = 0;
  size_t h_size = arr[n - 1] + 1;
  unsigned int *h = calloc(h_size, sizeof(unsigned int));
  if (h == NULL) {
    return;
  }
  for (size_t i = 0; i < n; ++i) {
    ++h[arr[i]];
  }
  int start = 0;
  for (size_t i = 0; i < h_size; ++i) {
    if (!start && h[i] >= 1) {
      start = 1;
    }
    if (start && h[i] == 0) {
      printf("missing %zu\n", i);
    }
  }
  free(h);
}

int main(int argc, char *argv[]) {

  unsigned int arr[] = {3, 6, 7, 11, 15};
  find_missing_elements_using_hashtable(arr,
                                        sizeof(arr) / sizeof(unsigned int));

  return 0;
}
