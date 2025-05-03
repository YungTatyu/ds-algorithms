#include "heap.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {0, 10, 25, 5, 40, 35};
  // for (size_t i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i) {
  //   heap_insert(arr, i);
  // }
  //
  // for (size_t i = sizeof(arr) / sizeof(arr[0]) - 1; i != 0; --i) {
  //   heap_delete(arr, i);
  // }
  heap_sort(arr, sizeof(arr) / sizeof(arr[0]));
  for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
    printf("%d ", arr[i]);
  }
  return 0;
}
