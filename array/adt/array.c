#include "array.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void array_delete(Array *arr) {
  array_free_contents(arr);
  free(arr);
}

void array_free_contents(Array *arr) { free(arr->a); }

void array_clear(Array *arr) {
  memset(arr->a, 0, arr->length * sizeof(int));
  arr->length = 0;
}

void array_display(Array *arr) {
  for (size_t i = 0; i < arr->length; ++i) {
    printf("%d", arr->a[i]);
  }
}
