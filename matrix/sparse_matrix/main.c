#include "sparse_matrix.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  SparseMatrix *m1 = sparse_marix_new(5, 6, 2);
  sparse_set(m1, 0, 0, 0, 1);
  sparse_set(m1, 1, 1, 1, 2);
  // sparse_set(m1, 2, 2, 2, 3);
  // sparse_set(m1, 3, 3, 3, 4);
  // sparse_set(m1, 4, 4, 4, 5);
  // sparse_set(m1, 5, 4, 5, 6);
  sparse_display(m1);
  printf("\n");
  SparseMatrix *m2 = sparse_marix_new(5, 6, 2);
  // sparse_set(m2, 0, 0, 0, 1);
  // sparse_set(m2, 1, 1, 1, 2);
  sparse_set(m2, 2, 2, 2, 3);
  sparse_set(m2, 3, 3, 3, 4);
  // sparse_set(m2, 4, 4, 1, 5);
  // sparse_set(m2, 5, 4, 4, 6);
  sparse_display(m2);
  printf("\n");
  SparseMatrix *sum = sparse_add(m1, m2);
  sparse_display(sum);
  return 0;
}
