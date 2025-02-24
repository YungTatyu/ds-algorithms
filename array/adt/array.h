#include <stddef.h>

struct Array {
  int *a;
  size_t size;
  size_t length;
};

typedef struct Array Array;
