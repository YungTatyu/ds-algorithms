#include "toeplitz_matrix.h"

int main(int argc, char *argv[]) {
  ToeplitxMatriz *m = toeplitz_matrix_new(5);
  toeplitz_matrix_set(m, 1, 1, 1);
  toeplitz_matrix_set(m, 1, 2, 2);
  toeplitz_matrix_set(m, 1, 3, 3);
  toeplitz_matrix_set(m, 1, 4, 4);
  toeplitz_matrix_set(m, 1, 5, 5);
  toeplitz_matrix_set(m, 2, 1, 6);
  toeplitz_matrix_set(m, 3, 1, 7);
  toeplitz_matrix_set(m, 4, 1, 8);
  toeplitz_matrix_set(m, 5, 1, 9);
  toeplitz_matrix_display(m);

  return 0;
}
