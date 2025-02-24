#include "array.h"
#include <stdlib.h>

Array *array_malloc(size_t size) {
  Array *ptr = (Array *)calloc(1, sizeof(Array));
  if (ptr == NULL) {
    return NULL;
  }
  array_malloc_a(ptr, size);
  if (ptr->a == NULL) {
    free(ptr);
    return NULL;
  }
  return ptr;
}

Array *array_malloc_a(Array *array, size_t size) {
  array->a = calloc(size, sizeof(int));
  if (array->a == NULL) {
    return NULL;
  }
  array->size = size;
  return array;
}
