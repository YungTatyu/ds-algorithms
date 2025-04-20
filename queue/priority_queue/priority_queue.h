#pragma once

#include <stddef.h>

struct PriotiryQueue {
  size_t size;
  size_t front;
  size_t rear;
  int *q;
};

typedef struct PriotiryQueue PriotiryQueue;

PriotiryQueue *pqueue_new(size_t size);

void pqueue_delete(PriotiryQueue *q);

void pqueue_enqueue(PriotiryQueue *q, int v);

int pqueue_dequeue(PriotiryQueue *q);

size_t pqueue_size(const PriotiryQueue *q);

int pqueue_empty(const PriotiryQueue *q);

int pqueue_full(const PriotiryQueue *q);

void pqueue_display(const PriotiryQueue *q);
