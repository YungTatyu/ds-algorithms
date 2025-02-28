#include <stddef.h>
#include <stdio.h>

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

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 6, 7};
  find_missing_elements(arr, sizeof(arr) / sizeof(int));

  return 0;
}
