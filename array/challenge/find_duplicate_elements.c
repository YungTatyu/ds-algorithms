
#include <stddef.h>
#include <stdio.h>
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

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 3, 4, 5, 6, 6, 6};

  find_duplicate_elements(arr, sizeof(arr) / sizeof(int));
  return 0;
}
