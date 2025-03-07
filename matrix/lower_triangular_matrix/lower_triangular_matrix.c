#include "lower_triangular_matrix.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

LowerTriangularMatrix *lower_triangular_matrix_new(size_t size) {
  LowerTriangularMatrix *m =
      (LowerTriangularMatrix *)calloc(1, sizeof(LowerTriangularMatrix));
  if (m == NULL) {
    return NULL;
  }
  m->arr = (int *)calloc(size, sizeof(int));
  if (m->arr == NULL) {
    free(m);
    return NULL;
  }
  m->size = size;
  return m;
}

void lower_triangular_matrix_set(LowerTriangularMatrix *m, size_t fi, size_t si,
                                 int v) {
  if (fi == 0 || si == 0 || si < fi) {
    return;
  }
  size_t index = lower_triangular_matrix_cal_index(fi, si);
  m->arr[index] = v;
}

int lower_triangular_matrix_get(const LowerTriangularMatrix *m, size_t fi,
                                size_t si) {
  if (fi == 0 || si == 0 || si < fi) {
    return 0;
  }
  size_t index = lower_triangular_matrix_cal_index(fi, si);
  return m->arr[index];
}

void lower_triangular_matrix_display(const LowerTriangularMatrix *m) {
  for (size_t fi = 0; fi < m->size; ++fi) {
    for (size_t si = 0; si < m->size; ++si) {
      if (fi >= si) {
        printf("%d ", m->arr[lower_triangular_matrix_cal_index(fi, si)]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

/**
 * 下三角行列 (3×3) の 1D 配列へのマッピング
 * fi: 行, si: 列
 *
 * 2D 行列の形:
 *
 *     [ a11  0    0  ]
 *     [ a21  a22  0  ]
 *     [ a31  a32  a33 ]
 *
 * これを 1D 配列に格納:
 *
 *     [ a11, a21, a22, a31, a32, a33 ]
 *
 * 各要素の 1D インデックス:
 *
 *     (1,1) ->  0
 *     (2,1) ->  1
 *     (2,2) ->  2
 *     (3,1) ->  3
 *     (3,2) ->  4
 *     (3,3) ->  5
 *
 * 計算式:
 * index = fi * (fi - 1) / 2 + si - 1
 */
size_t lower_triangular_matrix_cal_index(size_t fi, size_t si) {
  return fi * (fi - 1) / 2 + si - 1;
}
