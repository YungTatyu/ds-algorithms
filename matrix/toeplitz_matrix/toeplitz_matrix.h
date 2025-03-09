#pragma once

#include <stddef.h>

struct ToeplitxMatriz {
  int *arr;
  size_t size;
};

/**
 * Structure: ToeplitzMatrix
 * Description: Represents a Toeplitz matrix, which is a matrix where each
 *              descending diagonal from left to right is constant. This
 *              means that all elements along a diagonal have the same value.
 *
 * Members:
 * - size: The dimension 'n' of the n x n matrix.
 * - arr:  A one-dimensional array storing the unique elements of the
 *         Toeplitz matrix. For an n x n Toeplitz matrix, 'arr' contains
 *         2n - 1 elements: the first 'n' elements correspond to the first
 *         row, and the remaining 'n - 1' elements correspond to the first
 *         column (excluding the first element, as it's already included in
 *         the first row).
 *
 * Example of a 4x4 Toeplitz matrix:
 *
 *     | a  b  c  d |
 *     | e  a  b  c |
 *     | f  e  a  b |
 *     | g  f  e  a |
 *
 * Storage order in 'arr':
 * arr = [a, b, c, d, e, f, g]
 */
typedef struct ToeplitxMatriz ToeplitxMatriz;

ToeplitxMatriz *toeplitz_matrix_new(size_t size);

void toeplitz_matrix_set(ToeplitxMatriz *m, size_t fi, size_t si, int v);

int toeplitz_matrix_get(const ToeplitxMatriz *m, size_t fi, size_t si);

void toeplitz_matrix_display(const ToeplitxMatriz *m);

size_t toeplitz_matrix_cal_index(size_t n, size_t fi, size_t si);
