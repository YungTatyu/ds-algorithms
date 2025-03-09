#pragma once

#include <stddef.h>

struct TridiagonalMatrix {
  int *arr;
  size_t size;
};

/**
 * Structure: TridiagonalMatrix
 * Description: Represents a tridiagonal matrix, which is a square matrix
 *              with non-zero elements only on the main diagonal, the
 *              superdiagonal (above the main diagonal), and the
 *              subdiagonal (below the main diagonal).
 *
 * Members:
 * - size: The dimension 'n' of the n x n matrix.
 * - arr:  A one-dimensional array storing the non-zero elements.
 *
 * Example of a 4x4 tridiagonal matrix:
 *
 *     | b1  c1   0   0 |
 *     | a1  b2  c2   0 |
 *     |  0  a2  b3  c3 |
 *     |  0   0  a3  b4 |
 *
 * Storage order in 'arr':
 * arr = [c1, c2, c3, b1, b2, b3, b4, a1, a2, a3]
 */
typedef struct TridiagonalMatrix TridiagonalMatrix;

TridiagonalMatrix *tridiagonal_matrix_new(size_t size);

void tridiagonal_matrix_set(TridiagonalMatrix *m, size_t fi, size_t si, int v);

int tridiagonal_matrix_get(const TridiagonalMatrix *m, size_t fi, size_t si);

void tridiagonal_matrix_display(const TridiagonalMatrix *m);

size_t tridiagonal_matrix_cal_index(size_t n, size_t fi, size_t si);
