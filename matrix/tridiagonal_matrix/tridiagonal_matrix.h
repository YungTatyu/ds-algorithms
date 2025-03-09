#pragma once

#include <stddef.h>

struct TridiagonalMatrix {
  int *arr;
  size_t size;
};

typedef struct TridiagonalMatrix TridiagonalMatrix;

TridiagonalMatrix *tridiagonal_matrix_new(size_t size);

void tridiagonal_matrix_set(TridiagonalMatrix *m, size_t fi, size_t si, int v);

int tridiagonal_matrix_get(const TridiagonalMatrix *m, size_t fi, size_t si);

void tridiagonal_matrix_display(const TridiagonalMatrix *m);

size_t tridiagonal_matrix_cal_index(size_t n, size_t fi, size_t si);
