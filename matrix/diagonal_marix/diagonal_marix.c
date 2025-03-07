#include "diagonal_marix.h"
#include <stddef.h>
#include <stdio.h>

void diagonal_marix_set(DiagonalMatrix *m, size_t fi, size_t si, int v) {
  if (fi == 0 || fi != si) {
    return;
  }
  m->arr[fi - 1] = v;
}

int diagonal_marix_get(const DiagonalMatrix *m, size_t fi, size_t si) {
  if (fi == 0 || fi != si) {
    return 0;
  }
  return m->arr[fi - 1];
}

void diagonal_marix_display(const DiagonalMatrix *m) {
  for (size_t fi = 0; fi < m->size; ++fi) {
    for (size_t si = 0; si < m->size; ++si) {
      if (fi == si) {
        printf("%d ", m->arr[fi]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}
