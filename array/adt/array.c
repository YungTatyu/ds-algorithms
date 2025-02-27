#include "array.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

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

void array_append(Array *arr, int v) {
  if (arr->length >= arr->size) {
    return;
  }
  arr->a[arr->length] = v;
  ++(arr->length);
}

void array_insert(Array *arr, size_t index, int v) {
  if (index >= arr->size) {
    return;
  }
  if (index > arr->length) {
    arr->a[index] = v;
    arr->length = index + 1;
    return;
  }
  // optimize using memmove
  // for (size_t i = arr->length; i > index; --i) {
  //   arr->a[i] = arr->a[i - 1];
  // }
  memmove(&arr->a[index + 1], &arr->a[index],
          (arr->length - index) * sizeof(int));
  arr->a[index] = v;
  ++(arr->length);
}

int array_delete_ele(Array *arr, size_t index) {
  if (index >= arr->length) {
    return 0;
  }
  int re = arr->a[index];
  --(arr->length);
  memmove(&arr->a[index], &arr->a[index + 1],
          (arr->length - index) * sizeof(int));
  arr->a[arr->length] = 0;
  return re;
}

int array_get(const Array *arr, size_t index) {
  if (index >= arr->length) {
    return -1;
  }
  return arr->a[index];
}

void array_set(Array *arr, size_t index, int v) {
  if (index >= arr->size) {
    return;
  }
  arr->a[index] = v;
  if (index >= arr->length) {
    arr->length = index + 1;
  }
}

int array_max(const Array *arr) {
  int max = arr->a[0];
  for (size_t i = 1; i < arr->length; ++i) {
    if (arr->a[i] > max) {
      max = arr->a[i];
    }
  }
  return max;
}

int array_min(const Array *arr) {
  int min = arr->a[0];
  for (size_t i = 1; i < arr->length; ++i) {
    if (arr->a[i] < min) {
      min = arr->a[i];
    }
  }
  return min;
}

int array_sum(const Array *arr) {
  int sum = 0;
  for (size_t i = 0; i < arr->length; ++i) {
    sum += arr->a[i];
  }
  return sum;
}

float array_avg(const Array *arr) {
  return (float)array_sum(arr) / (float)arr->length;
}

ssize_t array_linear_search(const Array *arr, int key) {
  for (size_t i = 0; i < arr->length; ++i) {
    if (arr->a[i] == key) {
      return i;
    }
  }
  return -1;
}

static inline void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void array_reverse(Array *arr) {
  for (ssize_t min = 0, max = arr->length - 1; min < max; ++min, --max) {
    swap(&arr->a[min], &arr->a[max]);
  }
}

void array_left_shift(Array *arr) {
  if (arr->length == 0) {
    return;
  }
  memmove(&arr->a[0], &arr->a[1], (arr->length - 1) * sizeof(int));
  --(arr->length);
  arr->a[arr->length] = 0;
}

void array_left_rotate(Array *arr) {
  if (arr->length == 0 || arr->length == 1) {
    return;
  }
  int v = arr->a[0];
  memmove(&arr->a[0], &arr->a[1], (arr->length - 1) * sizeof(int));
  arr->a[arr->length - 1] = v;
}

void array_right_shift(Array *arr) {
  if (arr->length == 0) {
    return;
  }
  int is_max_length = arr->length == arr->size;
  memmove(&arr->a[1], &arr->a[0],
          (is_max_length ? arr->length - 1 : arr->length) * sizeof(int));
  if (!is_max_length) {
    ++(arr->length);
  }
  arr->a[0] = 0;
}

void array_right_rotate(Array *arr) {
  if (arr->length == 0 || arr->length == 1) {
    return;
  }
  int v = arr->a[arr->length - 1];
  memmove(&arr->a[1], &arr->a[0], (arr->length - 1) * sizeof(int));
  arr->a[0] = v;
}

ssize_t array_binary_search(const Array *arr, int key) {
  ssize_t l = 0, h = arr->length - 1;

  while (l <= h) {
    ssize_t m = (l + h) / 2;
    if (arr->a[m] == key) {
      return m;
    }
    if (arr->a[m] > key) {
      h = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

ssize_t array_rec_binary_search(const Array *arr, ssize_t low, ssize_t high,
                                int key) {
  if (low > high) {
    return -1;
  }
  ssize_t m = (low + high) / 2;
  if (arr->a[m] == key) {
    return m;
  }
  if (arr->a[m] > key) {
    return array_rec_binary_search(arr, low, m - 1, key);
  } else {
    return array_rec_binary_search(arr, m + 1, high, key);
  }
}
void array_display(Array *arr) {
  for (size_t i = 0; i < arr->length; ++i) {
    printf("%d, ", arr->a[i]);
  }
  printf("\n");
}
