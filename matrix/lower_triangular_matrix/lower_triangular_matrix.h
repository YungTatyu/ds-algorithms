#pragma once

#include <stddef.h>

struct LowerTriangularMatrix {
  int *arr;
  size_t size;
};

typedef struct LowerTriangularMatrix LowerTriangularMatrix;

LowerTriangularMatrix *lower_triangular_matrix_new(size_t size);

void lower_triangular_matrix_set(LowerTriangularMatrix *m, size_t fi, size_t si,
                                 int v);

int lower_triangular_matrix_get(const LowerTriangularMatrix *m, size_t fi,
                                size_t si);

void lower_triangular_matrix_display(const LowerTriangularMatrix *m);

size_t lower_triangular_matrix_cal_index(size_t fi, size_t si);
