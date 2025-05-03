#pragma once

#include <stddef.h>

void heap_insert(int arr[], size_t index);

int heap_delete(int arr[], size_t last_index);

void heapify(int arr[], size_t size);

void heap_sort(int arr[], size_t size);
