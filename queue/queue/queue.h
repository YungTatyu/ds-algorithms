#pragma once

#include <cstddef>

struct Queue {
  size_t size;
  size_t front;
  size_t rear;
  int *q;
};

typedef struct Queue Queue;

Queue *queue_new(size_t size);

void queue_delete(Queue *q);

int queue_empty(const Queue *q);
