#include "upper_triangular_matrix.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

UpperTriangularMatrix *upper_triangular_matrix_new(size_t size) {
  UpperTriangularMatrix *m =
      (UpperTriangularMatrix *)calloc(1, sizeof(UpperTriangularMatrix));
  if (m == NULL) {
    return NULL;
  }
  m->arr = (int *)calloc(size * (size + 1) / 2, sizeof(int));
  if (m->arr == NULL) {
    free(m);
    return NULL;
  }
  m->size = size;
  return m;
}

void upper_triangular_matrix_set(UpperTriangularMatrix *m, size_t fi, size_t si,
                                 int v) {
  if (fi == 0 || si == 0 || fi > si) {
    return;
  }
  size_t index = upper_triangular_matrix_cal_index(m->size, fi, si);
  m->arr[index] = v;
}

int upper_triangular_matrix_get(const UpperTriangularMatrix *m, size_t fi,
                                size_t si) {
  if (fi == 0 || si == 0 || fi > si) {
    return 0;
  }
  size_t index = upper_triangular_matrix_cal_index(m->size, fi, si);
  return m->arr[index];
}

void upper_triangular_matrix_display(const UpperTriangularMatrix *m) {
  for (size_t fi = 1; fi <= m->size; ++fi) {
    for (size_t si = 1; si <= m->size; ++si) {
      if (fi <= si) {
        printf("%d ",
               m->arr[upper_triangular_matrix_cal_index(m->size, fi, si)]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

size_t upper_triangular_matrix_cal_index(size_t n, size_t fi, size_t si) {
  return n * (fi - 1) - ((fi - 2) * (fi - 1) / 2) + si - fi;
}
