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
