#include "array.h"

int main(int argc, char *argv[]) {
  Array *arr = array_new(10);
  array_append(arr, 2);
  array_append(arr, 4);
  array_append(arr, 4);
  array_append(arr, 2);
  array_display(arr);
  array_insert(arr, 0, 0);
  array_display(arr);
  array_insert(arr, 9, 1);
  array_display(arr);
  return 0;
}
