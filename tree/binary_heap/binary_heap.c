#include "binary_heap.h"

/**
 * @brief Inserts a new element into the heap.
 *
 * This function treats the given array as a max-heap and inserts
 * a new element while maintaining the heap property.
 *
 * @param arr An integer array representing the heap.
 * @param index The index of the element to be inserted.
 *
 * @note The array `arr` must have sufficient allocated size,
 *       and `index` must be within the valid range of the array.
 */
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

void heap_delete(int arr[], size_t last_index) {
  int max = arr[0];
  arr[0] = arr[last_index];
  size_t parent_i = 0;
  size_t child_i = parent_i * 2 + 1;
  while (child_i < last_index) {
    if (arr[child_i + 1] > arr[child_i]) {
      ++child_i;
    }
    if (arr[parent_i] >= arr[child_i]) {
      break;
    }
    int temp = arr[parent_i];
    arr[parent_i] = arr[child_i];
    arr[child_i] = temp;
    parent_i = child_i;
    child_i = parent_i * 2 + 1;
  }
  arr[last_index] = max;
}
