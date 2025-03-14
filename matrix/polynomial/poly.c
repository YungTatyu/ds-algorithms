#include "poly.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Poly *poly_new(size_t size) {
  Poly *p = calloc(1, sizeof(Poly));
  if (p == NULL) {
    return NULL;
  }
  p->terms = calloc(size, sizeof(Term));
  if (p->terms == NULL) {
    free(p->terms);
    free(p);
    return NULL;
  }
  p->size = size;
  return p;
}

void poly_set(Poly *p, size_t i, int coeff, int exp) {
  p->terms[i].coeff = coeff;
  p->terms[i].exp = exp;
}

void poly_display(const Poly *p) {
  for (size_t i = 0; i < p->size; ++i) {
    printf("%dx%d+", p->terms[i].coeff, p->terms[i].exp);
  }
}

// Poly *poly_add(const Poly *p1, const Poly *p2);
