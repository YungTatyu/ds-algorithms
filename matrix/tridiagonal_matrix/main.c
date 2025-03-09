#include "tridiagonal_matrix.h"

int main(int argc, char *argv[]) {
  TridiagonalMatrix *m = tridiagonal_matrix_new(5);

  tridiagonal_matrix_set(m, 1, 2, 1);
  tridiagonal_matrix_set(m, 2, 3, 2);
  tridiagonal_matrix_set(m, 3, 4, 4);
  tridiagonal_matrix_set(m, 4, 5, 5);
  tridiagonal_matrix_set(m, 1, 1, 6);
  tridiagonal_matrix_set(m, 2, 2, 7);
  tridiagonal_matrix_set(m, 3, 3, 8);
  tridiagonal_matrix_set(m, 4, 4, 9);
  tridiagonal_matrix_set(m, 5, 5, 10);
  tridiagonal_matrix_set(m, 2, 1, 11);
  tridiagonal_matrix_set(m, 3, 2, 12);
  tridiagonal_matrix_set(m, 4, 3, 13);
  tridiagonal_matrix_set(m, 5, 4, 14);
  tridiagonal_matrix_display(m);
  return 0;
}
