#include "array.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Array *arr1 = array_new(10);
  array_append(arr1, 1);
  array_append(arr1, 2);
  array_append(arr1, 4);
  array_append(arr1, 10);
  array_append(arr1, 1000);
  // array_display(arr);
  // array_insert(arr, 0, 0);
  // array_display(arr);
  // array_insert(arr, 9, 1);
  // array_display(arr);
  //
  // array_delete_ele(arr, 2);
  // array_display(arr);
  // array_delete_ele(arr, 0);
  // array_display(arr);
  // array_delete_ele(arr, arr->length - 1);
  // array_display(arr);
  // array_delete_ele(arr, arr->length);
  // array_display(arr);

  Array *arr2 = array_new(15);
  array_append(arr2, -7);
  array_append(arr2, -2);
  array_append(arr2, -1);
  array_append(arr2, 2);
  array_append(arr2, 4);
  array_append(arr2, 5);
  array_append(arr2, 10);

  Array *arr = array_intersection(arr1, arr2);
  array_display(arr);

  // array_set(sorted_arr, 0, 24);
  // array_display(sorted_arr);
  // array_set(sorted_arr, 9, 24);
  // array_display(sorted_arr);
  // printf("%d\n", array_get(sorted_arr, 0));
  // printf("%d\n", array_sum(sorted_arr));

  return 0;
}
