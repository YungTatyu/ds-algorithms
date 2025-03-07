#include "lower_triangular_matrix.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  LowerTriangularMatrix *m = lower_triangular_matrix_new(4);
  lower_triangular_matrix_set(m, 1, 2, 24);
  lower_triangular_matrix_set(m, 1, 1, 1);
  lower_triangular_matrix_set(m, 2, 2, 11);
  lower_triangular_matrix_set(m, 2, 1, 2);
  lower_triangular_matrix_set(m, 3, 1, 20);
  lower_triangular_matrix_set(m, 4, 4, 44);
  printf("%d\n", lower_triangular_matrix_get(m, 1, 1));
  lower_triangular_matrix_display(m);
  return 0;
  ;
}
