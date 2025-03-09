#include "tridiagonal_matrix.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

TridiagonalMatrix *tridiagonal_matrix_new(size_t size) {
  TridiagonalMatrix *m =
      (TridiagonalMatrix *)calloc(1, sizeof(TridiagonalMatrix));
  if (m == NULL) {
    return NULL;
  }
  // size + size - 1 + size - 1
  m->arr = (int *)calloc(3 * size - 2, sizeof(int));
  if (m->arr == NULL) {
    free(m);
    return NULL;
  }
  m->size = size;
  return m;
}

void tridiagonal_matrix_set(TridiagonalMatrix *m, size_t fi, size_t si, int v) {
  int diff = fi - si;
  if (fi == si || diff == 1 || diff == -1) {
    size_t index = tridiagonal_matrix_cal_index(m->size, fi, si);
    m->arr[index] = v;
  }
}

int tridiagonal_matrix_get(const TridiagonalMatrix *m, size_t fi, size_t si) {
  int diff = fi - si;
  if (fi == si || diff == 1 || diff == -1) {
    size_t index = tridiagonal_matrix_cal_index(m->size, fi, si);
    return m->arr[index];
  }
  return 0;
}

void tridiagonal_matrix_display(const TridiagonalMatrix *m) {
  for (size_t fi = 1; fi <= m->size; ++fi) {
    for (size_t si = 1; si <= m->size; ++si) {
      int diff = fi - si;
      if (fi == si || diff == 1 || diff == -1) {
        printf("%d ", m->arr[tridiagonal_matrix_cal_index(m->size, fi, si)]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

size_t tridiagonal_matrix_cal_index(size_t n, size_t fi, size_t si) {
  if (fi - si == -1) {
    return fi - 2;
  } else if (fi == si) {
    return n - 2 + fi;
  } else if (fi - si == 1) {
    return 2 * n - 2 + si;
  }
  return 0;
}
