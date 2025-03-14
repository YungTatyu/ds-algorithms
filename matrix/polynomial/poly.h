#pragma once

#include <stddef.h>

struct Term {
  int coeff; // 係数
  int exp;   // 指数
};

typedef struct Term Term;

struct Poly {
  size_t size;
  Term *terms;
};

typedef struct Poly Poly;

Poly *poly_new(size_t size);

void poly_set(Poly *p, size_t i, int coeff, int exp);

void poly_display(const Poly *p);

Poly *poly_add(const Poly *p1, const Poly *p2);
