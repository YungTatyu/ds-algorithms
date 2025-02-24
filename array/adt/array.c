#include "array.h"
#include <stddef.h>
#include <stdio.h>
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

void array_delete(Array *array) {
  array_free_contents(array);
  free(array);
}

Array *array_free_contents(Array *array) {
  free(array->a);
  return array;
}

void array_display(Array *array) {
  for (size_t i = 0; i < array->length; ++i) {
    printf("%d", array->a[i]);
  }
}
