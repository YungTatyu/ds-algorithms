#pragma once

#include <stddef.h>

struct UpperTriangularMatrix {
  int *arr;
  size_t size;
};

/**
 * @brief Structure representing an upper triangular matrix.
 *
 * An upper triangular matrix is a square matrix in which all elements below the
 * main diagonal are zero. For example, a 4x4 upper triangular matrix is
 * represented as:
 *
 * [ a₁₁ a₁₂ a₁₃ a₁₄ ]
 * [ 0    a₂₂ a₂₃ a₂₄ ]
 * [ 0    0    a₃₃ a₃₄ ]
 * [ 0    0    0    a₄₄ ]
 */
typedef struct UpperTriangularMatrix UpperTriangularMatrix;

UpperTriangularMatrix *upper_triangular_matrix_new(size_t size);

void upper_triangular_matrix_set(UpperTriangularMatrix *m, size_t fi, size_t si,
                                 int v);

int upper_triangular_matrix_get(const UpperTriangularMatrix *m, size_t fi,
                                size_t si);

void upper_triangular_matrix_display(const UpperTriangularMatrix *m);

size_t upper_triangular_matrix_cal_index(size_t n, size_t fi, size_t si);
