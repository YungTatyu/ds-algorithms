#include "poly.h"

int main(int argc, char *argv[]) {

  Poly *p = poly_new(3);
  poly_set(p, 0, 2, 3);
  poly_set(p, 1, 3, 4);
  poly_set(p, 2, 5, 5);
  poly_display(p);

  return 0;
}
