#include "upper_triangular_matrix.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  UpperTriangularMatrix *m = upper_triangular_matrix_new(4);
  upper_triangular_matrix_set(m, 1, 2, 12);
  upper_triangular_matrix_set(m, 1, 1, 11);
  upper_triangular_matrix_set(m, 1, 4, 14);
  upper_triangular_matrix_set(m, 2, 2, 22);
  upper_triangular_matrix_set(m, 2, 1, 21);
  upper_triangular_matrix_set(m, 2, 3, 23);
  upper_triangular_matrix_set(m, 2, 4, 24);
  upper_triangular_matrix_set(m, 2, 1, 21);
  upper_triangular_matrix_set(m, 1, 3, 13);
  upper_triangular_matrix_set(m, 3, 3, 33);
  upper_triangular_matrix_set(m, 3, 4, 34);
  upper_triangular_matrix_set(m, 4, 4, 44);
  upper_triangular_matrix_set(m, 4, 3, 43);
  printf("%d\n", upper_triangular_matrix_get(m, 1, 1));
  upper_triangular_matrix_display(m);
  return 0;
  ;
}
