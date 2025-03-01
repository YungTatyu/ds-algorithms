
#include <stddef.h>
#include <stdio.h>
void find_duplicate_elements(const int *arr, size_t size) {
  int dup = arr[0] + 1;
  for (size_t i = 0; i < size - 1; ++i) {
    if (arr[i] == arr[i + 1] && arr[i] != dup) {
      printf("%d is duplicate\n", arr[i]);
      dup = arr[i];
    }
  }
}

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 4, 5, 6};
  find_duplicate_elements(arr, sizeof(arr) / sizeof(int));
  return 0;
}
