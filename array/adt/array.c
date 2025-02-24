#include "array.h"
#include <stdlib.h>

Array *array_new(size_t size) {
  Array *ptr = (Array *)calloc(1, sizeof(Array));
  if (ptr == NULL) {
    return NULL;
  }
  array_init(ptr, size);
  if (ptr->a == NULL) {
    free(ptr);
    return NULL;
  }
  return ptr;
}

Array *array_init(Array *array, size_t size) {
  array->a = calloc(size, sizeof(int));
  if (array->a == NULL) {
    return NULL;
  }
  array->size = size;
  return array;
}
