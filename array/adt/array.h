#include <stddef.h>
#include <stdlib.h>

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
Array *array_malloc(size_t size);

/**
 * @brief create actual array with size of given size in a variable
 * @returns Array*|NULL
 */
Array *array_malloc_a(Array *array, size_t size);
