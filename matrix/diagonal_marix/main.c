#include "diagonal_marix.h"

int main(int argc, char *argv[]) {
  DiagonalMatrix *m = diagonal_marix_new(10);

  diagonal_marix_set(m, 1, 1, 2);
  diagonal_marix_set(m, 2, 2, 4);
  diagonal_marix_set(m, 3, 3, 6);
  diagonal_marix_display(m);

  return 0;
}
