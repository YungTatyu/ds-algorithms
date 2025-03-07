#pragma once

#include <stddef.h>

struct DiagonalMatrix {
  int *arr;
  size_t size;
};

// --------------------------------------------
// Structure representing a diagonal matrix
// A diagonal matrix is a square matrix where
// all non-diagonal elements are zero.
//
// Example (3x3 diagonal matrix):
//
//    | d1  0   0  |
//    |  0  d2  0  |
//    |  0   0  d3 |
//
// Only the diagonal elements {d1, d2, d3, ...}
// are stored to save memory.
// --------------------------------------------
typedef struct DiagonalMatrix DiagonalMatrix;

DiagonalMatrix *diagonal_marix_new(size_t size);

void diagonal_marix_set(DiagonalMatrix *m, size_t fi, size_t si, int v);

int diagonal_marix_get(const DiagonalMatrix *m, size_t fi, size_t si);

void diagonal_marix_display(const DiagonalMatrix *m);
