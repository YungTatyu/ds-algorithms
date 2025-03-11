#include "sparse_matrix.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

SparseMatrix *sparse_marix_new(size_t row_num, size_t col_num, size_t size) {
  SparseMatrix *m = (SparseMatrix *)calloc(1, sizeof(SparseMatrix));
  if (m == NULL) {
    return NULL;
  }
  m->row_num = row_num;
  m->col_num = col_num;
  m->ele = (SparseElement *)calloc(size, sizeof(SparseElement));
  if (m->ele == NULL) {
    free(m);
    return NULL;
  }
  return m;
}

void sparse_set(SparseMatrix *m, size_t ele_index, size_t ri, size_t ci,
                int v) {
  SparseElement *ele = &m->ele[ele_index];
  ele->ri = ri;
  ele->ci = ci;
  ele->value = v;
}

void sparse_display(const SparseMatrix *m) {
  size_t ele_index = 0;
  for (size_t ri = 0; ri < m->row_num; ++ri) {
    for (size_t ci = 0; ci < m->col_num; ++ci) {
      if (m->ele[ele_index].ri == ri && m->ele[ele_index].ci == ci) {
        printf("%d ", m->ele[ele_index].value);
        ++ele_index;
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}
