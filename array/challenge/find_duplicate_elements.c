#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void find_duplicate_elements(const int *arr, size_t size) {
  int dup = arr[0] + 1;
  size_t count = 0;
  for (size_t i = 0; i < size - 1; ++i) {
    int is_dup = arr[i] == arr[i + 1];
    if (is_dup && arr[i] != dup) {
      printf("%d is duplicate\n", arr[i]);
      dup = arr[i];
      ++count;
    }
    if (is_dup) {
      ++count;
    }
  }
  printf("%zu duplicate\n", count);
}

void find_duplicate_elements_using_hashtable(const unsigned int *arr,
                                             size_t size) {
  size_t h_size = arr[size - 1] + 1;
  unsigned int *h = (unsigned int *)calloc(h_size, sizeof(unsigned int));
  for (size_t i = 0; i < size; ++i) {
    ++h[arr[i]];
  }
  for (size_t i = 0; i < h_size; ++i) {
    if (h[i] > 1) {
      printf("dup value: %zu, count: %d\n", i, h[i]);
    }
  }
}
int main(int argc, char *argv[]) {

  unsigned int arr[] = {1, 2, 3, 3, 4, 5, 6, 6, 6};

  find_duplicate_elements_using_hashtable(arr,
                                          sizeof(arr) / sizeof(unsigned int));
  return 0;
}
