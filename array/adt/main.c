#include "array.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  // Array *arr = array_new(10);
  // array_append(arr, 2);
  // array_append(arr, 4);
  // array_append(arr, 4);
  // array_append(arr, 2);
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

  Array *sorted_arr = array_new(15);
  array_append(sorted_arr, 24);
  array_append(sorted_arr, -1);
  array_append(sorted_arr, -2);
  array_append(sorted_arr, 3);
  array_append(sorted_arr, 5);
  array_append(sorted_arr, -7);
  array_append(sorted_arr, 10);
  array_display(sorted_arr);
  array_rearrenge(sorted_arr);
  array_display(sorted_arr);

  // array_set(sorted_arr, 0, 24);
  // array_display(sorted_arr);
  // array_set(sorted_arr, 9, 24);
  // array_display(sorted_arr);
  // printf("%d\n", array_get(sorted_arr, 0));
  // printf("%d\n", array_sum(sorted_arr));

  return 0;
}
