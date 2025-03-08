#pragma once

#include <stddef.h>

struct UpperTriangularMatrix {
  int *arr;
  size_t size;
};

typedef struct UpperTriangularMatrix UpperTriangularMatrix;

UpperTriangularMatrix *upper_triangular_matrix_new(size_t size);

void upper_triangular_matrix_set(UpperTriangularMatrix *m, size_t fi, size_t si,
                                 int v);

int upper_triangular_matrix_get(const UpperTriangularMatrix *m, size_t fi,
                                size_t si);

void upper_triangular_matrix_display(const UpperTriangularMatrix *m);

size_t upper_triangular_matrix_cal_index(size_t n, size_t fi, size_t si);
