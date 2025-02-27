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

  Array *sorted_arr = array_new(10);
  array_append(sorted_arr, 0);
  array_append(sorted_arr, 1);
  array_append(sorted_arr, 2);
  array_append(sorted_arr, 3);
  array_append(sorted_arr, 5);
  array_append(sorted_arr, 7);
  array_append(sorted_arr, 10);
  array_display(sorted_arr);

  printf("%zd", array_binary_search(sorted_arr, 2));
  printf("%zd", array_binary_search(sorted_arr, 0));
  printf("%zd", array_binary_search(sorted_arr, 10));
  printf("%zd", array_binary_search(sorted_arr, -2));
  printf("%zd", array_binary_search(sorted_arr, 12));
  printf("%zd",
         array_rec_binary_search(sorted_arr, 0, sorted_arr->length - 1, 2));
  printf("%zd",
         array_rec_binary_search(sorted_arr, 0, sorted_arr->length - 1, 0));
  printf("%zd",
         array_rec_binary_search(sorted_arr, 0, sorted_arr->length - 1, 10));
  printf("%zd",
         array_rec_binary_search(sorted_arr, 0, sorted_arr->length - 1, -2));
  printf("%zd",
         array_rec_binary_search(sorted_arr, 0, sorted_arr->length - 1, 12));
  return 0;
}
