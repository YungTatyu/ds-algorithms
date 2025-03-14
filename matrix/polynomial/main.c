#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  Poly *p = poly_new(3);
  poly_set(p, 0, 5, 5);
  poly_set(p, 1, 3, 4);
  poly_set(p, 2, 2, 3);
  poly_display(p);
  printf("\n");
  Poly *p2 = poly_new(5);
  poly_set(p2, 0, 4, 4);
  poly_set(p2, 1, 3, 3);
  poly_set(p2, 2, 2, 2);
  poly_set(p2, 3, 1, 1);
  poly_set(p2, 4, 5, 0);
  poly_display(p2);
  printf("\n");
  Poly *sum = poly_add(p, p2);
  poly_display(sum);
  printf("\n");

  free(p->terms);
  free(p2->terms);
  free(sum->terms);
  free(p);
  free(p2);
  free(sum);

  return 0;
}
