#include "dequeue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Dequeue *dequeue_new(size_t size) {
  Dequeue *q = calloc(1, sizeof(Dequeue));
  if (q == NULL) {
    return NULL;
  }
  q->q = calloc(size, sizeof(int));
  if (q->q == NULL) {
    free(q);
    return NULL;
  }
  q->capacity = size;
  return q;
}

void dequeue_delete(Dequeue *q) {
  free(q->q);
  free(q);
}

size_t dequeue_size(const Dequeue *q) { return q->size; }

int dequeue_empty(const Dequeue *q) { return q->size == 0; }

int dequeue_full(const Dequeue *q) { return q->size == q->capacity - 1; }

inline static size_t dequeue_index(const Dequeue *q, size_t index) {
  return index % q->capacity;
}

void dequeue_push_front(Dequeue *q, int v) {
  if (dequeue_full(q)) {
    return;
  }
  if (q->front == 0) {
    q->front = q->capacity - 1;
  } else {
    --(q->front);
  }
  q->q[q->front] = v;
  ++(q->size);
}

void dequeue_push_back(Dequeue *q, int v) {
  if (dequeue_full(q)) {
    return;
  }
  q->q[q->rear] = v;
  q->rear = dequeue_index(q, q->rear + 1);
  ++(q->size);
}

int dequeue_pop_front(Dequeue *q) {
  if (dequeue_empty(q)) {
    return -1;
  }
  int re = q->q[q->front];
  q->front = dequeue_index(q, q->front + 1);
  --(q->size);
  return re;
}

int dequeue_pop_back(Dequeue *q) {
  if (dequeue_empty(q)) {
    return -1;
  }
  q->rear = q->rear == 0 ? q->capacity - 1 : q->rear - 1;
  int re = q->q[q->rear];
  --(q->size);
  return re;
}

void dequeue_display(const Dequeue *q) {
  if (dequeue_empty(q)) {
    return;
  }
  size_t i = q->front;
  while (i != q->rear) {
    printf("%d ", q->q[i]);
    i = dequeue_index(q, i + 1);
  }
  printf("\n");
}
