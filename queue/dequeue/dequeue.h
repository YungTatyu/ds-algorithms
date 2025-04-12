#pragma once

#include <stddef.h>

struct Dequeue {
  size_t size;
  size_t capacity;
  size_t front;
  size_t rear;
  int *q;
};

typedef struct Dequeue Dequeue;

Dequeue *dequeue_new(size_t size);

void dequeue_delete(Dequeue *q);

void dequeue_push_front(Dequeue *q, int v);

void dequeue_push_back(Dequeue *q, int v);

int dequeue_pop_front(Dequeue *q);

int dequeue_pop_back(Dequeue *q);

size_t dequeue_size(const Dequeue *q);

int dequeue_empty(const Dequeue *q);

int dequeue_full(const Dequeue *q);

void dequeue_display(const Dequeue *q);
