#include "poly.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Poly *poly_new(size_t size) {
  Poly *p = calloc(1, sizeof(Poly));
  if (p == NULL) {
    return NULL;
  }
  p->terms = calloc(size, sizeof(Term));
  if (p->terms == NULL) {
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
  for (size_t i = 0; i < p->size - 1; ++i) {
    printf("%dx%d+", p->terms[i].coeff, p->terms[i].exp);
  }
  printf("%dx%d", p->terms[p->size - 1].coeff, p->terms[p->size - 1].exp);
}

Poly *poly_add(const Poly *p1, const Poly *p2) {
  Poly *sum = calloc(1, sizeof(Poly));
  if (sum == NULL) {
    return NULL;
  }
  sum->terms = calloc(p1->size + p2->size, sizeof(Term));
  if (sum->terms == NULL) {
    free(sum);
    return NULL;
  }
  size_t pi = 0, p1i = 0, p2i = 0;
  while (p1i < p1->size && p2i < p2->size) {
    if (p1->terms[p1i].exp > p2->terms[p2i].exp) {
      memcpy(&sum->terms[pi], &p1->terms[p1i], sizeof(Term));
      ++p1i;
    } else if (p1->terms[p1i].exp < p2->terms[p2i].exp) {
      memcpy(&sum->terms[pi], &p2->terms[p2i], sizeof(Term));
      ++p2i;
    } else {
      sum->terms[pi].coeff = p1->terms[p1i].coeff + p2->terms[p2i].coeff;
      sum->terms[pi].exp = p1->terms[p1i].exp;
      ++p1i;
      ++p2i;
    }
    ++pi;
  }
  memcpy(&sum->terms[pi], &p1->terms[p1i], sizeof(Term) * (p1->size - p1i));
  memcpy(&sum->terms[pi], &p2->terms[p2i], sizeof(Term) * (p2->size - p2i));
  size_t max = p1i >= p2i ? p1->size : p2->size;
  sum->size = max + (p1->size - p1i) + (p2->size - p2i);
  return sum;
}
