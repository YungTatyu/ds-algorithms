#include "sparse_matrix.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SparseMatrix *sparse_marix_new(size_t row_num, size_t col_num, size_t size) {
  SparseMatrix *m = (SparseMatrix *)calloc(1, sizeof(SparseMatrix));
  if (m == NULL) {
    return NULL;
  }
  m->row_num = row_num;
  m->col_num = col_num;
  m->size = size;
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
      if (ele_index < m->size && m->ele[ele_index].ri == ri &&
          m->ele[ele_index].ci == ci) {
        printf("%d ", m->ele[ele_index].value);
        ++ele_index;
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

SparseMatrix *sparse_add(const SparseMatrix *m1, const SparseMatrix *m2) {
  if (m1->row_num != m2->row_num || m1->col_num != m2->col_num) {
    return NULL;
  }
  SparseMatrix *sum = calloc(1, sizeof(SparseMatrix));
  if (sum == NULL) {
    return NULL;
  }
  sum->row_num = m1->row_num;
  sum->col_num = m1->col_num;
  sum->ele = calloc(m1->size + m2->size, sizeof(SparseElement));
  if (sum->ele == NULL) {
    free(sum);
    return NULL;
  }
  size_t m1i = 0, m2i = 0, si = 0;
  while (m1i < m1->size && m2i < m2->size) {
    if (m1->ele[m1i].ri < m2->ele[m2i].ri) {
      memcpy(&sum->ele[si], &m1->ele[m1i], sizeof(SparseElement));
      ++m1i;
    } else if (m1->ele[m1i].ri > m2->ele[m2i].ri) {
      memcpy(&sum->ele[si], &m2->ele[m2i], sizeof(SparseElement));
      ++m2i;
    } else {
      if (m1->ele[m1i].ci < m2->ele[m2i].ci) {
        memcpy(&sum->ele[si], &m1->ele[m1i], sizeof(SparseElement));
        ++m1i;
      } else if (m1->ele[m1i].ci > m2->ele[m2i].ci) {
        memcpy(&sum->ele[si], &m2->ele[m2i], sizeof(SparseElement));
        ++m2i;
      } else {
        memcpy(&sum->ele[si], &m1->ele[m1i], sizeof(SparseElement));
        sum->ele[si].value += m2->ele[m2i].value;
        ++m1i;
        ++m2i;
      }
    }
    ++si;
  }
  memcpy(&sum->ele[si], &m1->ele[m1i],
         sizeof(SparseElement) * (m1->size - m1i));
  memcpy(&sum->ele[si], &m2->ele[m2i],
         sizeof(SparseElement) * (m2->size - m2i));
  size_t max = m1->size >= m2->size ? m1->size : m2->size;
  sum->size += max + (m1->size - m1i) + (m2->size - m2i);
  return sum;
}
