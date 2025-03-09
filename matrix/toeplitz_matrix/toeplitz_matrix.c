#include "toeplitz_matrix.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

ToeplitxMatriz *toeplitz_matrix_new(size_t size) {
  ToeplitxMatriz *m = (ToeplitxMatriz *)calloc(1, sizeof(ToeplitxMatriz));
  if (m == NULL) {
    return NULL;
  }
  m->arr = (int *)calloc(size + size - 1, sizeof(int));
  if (m->arr == NULL) {
    free(m);
    return NULL;
  }
  m->size = size;
  return m;
}

void toeplitz_matrix_set(ToeplitxMatriz *m, size_t fi, size_t si, int v) {
  if (fi == 0 || si == 0) {
    return;
  }
  size_t index = toeplitz_matrix_cal_index(m->size, fi, si);
  m->arr[index] = v;
}

int toeplitz_matrix_get(const ToeplitxMatriz *m, size_t fi, size_t si) {
  if (fi == 0 || si == 0) {
    return 0;
  }
  size_t index = toeplitz_matrix_cal_index(m->size, fi, si);
  return m->arr[index];
}

void toeplitz_matrix_display(const ToeplitxMatriz *m) {
  for (size_t fi = 1; fi <= m->size; ++fi) {
    for (size_t si = 1; si <= m->size; ++si) {
      printf("%d ", m->arr[toeplitz_matrix_cal_index(m->size, fi, si)]);
    }
    printf("\n");
  }
}

size_t toeplitz_matrix_cal_index(size_t n, size_t fi, size_t si) {
  if (si >= fi) {
    return si - fi;
  } else {
    return n + fi - si - 1;
  }
  return 0;
}
