#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>

struct Array {
  int *a;
  size_t size;
  size_t length;
};

typedef struct Array Array;

/**
 * @brief create Array instance in heap
 * @returns Array*|NULL
 */
Array *array_new(size_t size);

/**
 * @brief create actual array with size of given size in a variable
 * @returns Array*|NULL
 */
Array *array_init(Array *arr, size_t size);

void array_delete(Array *arr);

void array_free_contents(Array *arr);

void array_clear(Array *arr);

void array_append(Array *arr, int v);

void array_insert(Array *arr, size_t index, int v);

int array_delete_ele(Array *arr, size_t index);

int array_get(const Array *arr, size_t index);

void array_set(Array *arr, size_t index, int v);

int array_max(const Array *arr);

int array_min(const Array *arr);

int array_sum(const Array *arr);

float array_avg(const Array *arr);

void array_reverse(Array *arr);

void array_left_shift(Array *arr);

void array_left_rotate(Array *arr);

void array_right_shift(Array *arr);

void array_right_rotate(Array *arr);

void array_insert_sort(Array *arr, int v);

int array_is_sorted(const Array *arr);

void array_rearrenge(Array *arr);

ssize_t array_linear_search(const Array *arr, int key);

ssize_t array_binary_search(const Array *arr, int key);

ssize_t array_rec_binary_search(const Array *arr, ssize_t low, ssize_t high,
                                int key);

void array_display(Array *arr);
