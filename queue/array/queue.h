#pragma once

#include <stddef.h>

struct Queue {
  size_t size;
  size_t front;
  size_t rear;
  int *q;
};

typedef struct Queue Queue;

Queue *queue_new(size_t size);

void queue_delete(Queue *q);

void queue_enqueue(Queue *q, int v);

int queue_dequeue(Queue *q);

size_t queue_size(const Queue *q);

int queue_empty(const Queue *q);

int queue_full(const Queue *q);

void queue_display(const Queue *q);
