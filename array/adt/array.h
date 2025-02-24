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
Array *array_new(size_t size);

/**
 * @brief create actual array with size of given size in a variable
 * @returns Array*|NULL
 */
Array *array_init(Array *array, size_t size);

void array_delete(Array *array);

Array *array_free_contents(Array *array);

void array_display(Array *array);
