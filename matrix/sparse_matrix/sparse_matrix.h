#pragma once

#include <stddef.h>

struct SparseElement {
  size_t ri;
  size_t ci;
  int value;
};

typedef struct SparseElement SparseElement;

struct SparseMatrix {
  size_t row_num;
  size_t col_num;
  SparseElement *ele;
  size_t size;
};

typedef struct SparseMatrix SparseMatrix;

SparseMatrix *sparse_marix_new(size_t row_num, size_t col_num, size_t size);

void sparse_set(SparseMatrix *m, size_t ele_index, size_t ri, size_t ci, int v);

void sparse_display(const SparseMatrix *m);

SparseMatrix *sparse_add(const SparseMatrix *m1, const SparseMatrix *m2);
