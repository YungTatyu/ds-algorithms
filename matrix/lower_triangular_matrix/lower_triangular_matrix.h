#pragma once

#include <stddef.h>

struct LowerTriangularMatrix {
  int *arr;
  size_t size;
};

/**
 * @brief Structure representing a lower triangular matrix.
 *
 * A lower triangular matrix is a square matrix in which all elements above the
 * main diagonal are zero. For example, a 4x4 lower triangular matrix is
 * represented as:
 *
 * [ a₁₁  0    0    0  ]
 * [ a₂₁ a₂₂  0    0  ]
 * [ a₃₁ a₃₂ a₃₃  0  ]
 * [ a₄₁ a₄₂ a₄₃ a₄₄ ]
 */
typedef struct LowerTriangularMatrix LowerTriangularMatrix;

LowerTriangularMatrix *lower_triangular_matrix_new(size_t size);

void lower_triangular_matrix_set(LowerTriangularMatrix *m, size_t fi, size_t si,
                                 int v);

int lower_triangular_matrix_get(const LowerTriangularMatrix *m, size_t fi,
                                size_t si);

void lower_triangular_matrix_display(const LowerTriangularMatrix *m);

size_t lower_triangular_matrix_cal_index(size_t fi, size_t si);
