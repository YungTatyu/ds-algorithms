#include "binary_heap.h"

void heap_insert(int arr[], size_t index) {
  int new_value = arr[index];
  while (index > 0) {
    size_t parent_index = (index - 1) / 2;
    if (new_value <= arr[parent_index]) {
      break;
    }
    arr[index] = arr[parent_index];
    index = parent_index;
  }
  arr[index] = new_value;
}
