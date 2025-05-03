#include "heap.h"

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

/**
 * @brief Deletes the maximum element (root) from a max-heap and restores the
 * heap property.
 *
 * This function removes the root element (maximum in a max-heap), replaces it
 * with the last element in the heap, and then performs a "heapify-down"
 * operation to restore the max-heap property.
 *
 * @param arr The array representing the heap.
 * @param last_index The index of the last element in the heap (size of the
 * heap). Note: The array should have at least one element.
 */
int heap_delete(int arr[], size_t last_index) {
  int max = arr[0];
  arr[0] = arr[last_index];
  size_t parent_i = 0;
  size_t child_i = parent_i * 2 + 1;
  while (child_i < last_index) {
    // compare left child and right child and get a bigger one
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
  return max;
}

/**
 * @brief Converts an array into a max heap.
 *
 * This function rearranges the elements of the input array to satisfy
 * the max heap property, where each parent node is greater than or
 * equal to its child nodes.
 *
 * @param arr The array to be heapified.
 * @param size The size of the array.
 *
 * @note Time Complexity: O(n), where n is the size of the array.
 */
void heapify(int arr[], size_t size) {
  size_t i = size / 2 - 1;
  while (1) {
    size_t parent_i = i;
    size_t child_i = i * 2 + 1;
    while (child_i < size - 1) {
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
    if (i == 0) {
      break;
    }
    --i;
  }
}

/**
 * @brief Sorts an array using the heap sort algorithm.
 *
 * This function sorts an array in ascending order by first building a max-heap
 * from the input array and then repeatedly extracting the maximum element from
 * the heap and placing it at the end of the array.
 *
 * Time Complexity:
 * - Building the max-heap: O(n log n)
 * - Extracting elements and heapifying: O(n log n)
 * - Overall: O(n log n)
 *
 * @param arr The array to be sorted.
 * @param size The number of elements in the array.
 */
void heap_sort(int arr[], size_t size) {
  if (size <= 1) {
    return;
  }
  heapify(arr, size);
  for (size_t i = size - 1; i != 0; --i) {
    heap_delete(arr, i);
  }
}
