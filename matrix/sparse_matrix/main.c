#include "sparse_matrix.h"

int main(int argc, char *argv[]) {
  SparseMatrix *m = sparse_marix_new(5, 6, 6);
  sparse_set(m, 0, 0, 0, 1);
  sparse_set(m, 1, 1, 1, 2);
  sparse_set(m, 2, 2, 2, 3);
  sparse_set(m, 3, 3, 3, 4);
  sparse_set(m, 4, 4, 4, 5);
  sparse_set(m, 5, 4, 5, 6);
  sparse_display(m);
  return 0;
}
