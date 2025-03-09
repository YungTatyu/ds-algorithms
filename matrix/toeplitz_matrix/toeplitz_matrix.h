#pragma once

#include <stddef.h>

struct ToeplitxMatriz {
  int *arr;
  size_t size;
};

typedef struct ToeplitxMatriz ToeplitxMatriz;

ToeplitxMatriz *toeplitz_matrix_new(size_t size);

void toeplitz_matrix_set(ToeplitxMatriz *m, size_t fi, size_t si, int v);

int toeplitz_matrix_get(const ToeplitxMatriz *m, size_t fi, size_t si);

void toeplitz_matrix_display(const ToeplitxMatriz *m);

size_t toeplitz_matrix_cal_index(size_t n, size_t fi, size_t si);
