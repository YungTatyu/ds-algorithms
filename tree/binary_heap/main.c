#include "binary_heap.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {0, 10, 20, 30, 25, 5, 40, 35, 0, 35};
  for (size_t i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i) {
    heap_insert(arr, i);
  }

  for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
    printf("%d ", arr[i]);
  }
  return 0;
}
