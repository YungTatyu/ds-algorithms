#include "queue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Queue *queue_new(size_t size) {
  Queue *q = calloc(1, sizeof(Queue));
  if (q == NULL) {
    return NULL;
  }
  q->q = calloc(size, sizeof(int));
  if (q->q == NULL) {
    free(q);
    return NULL;
  }
  q->size = size;
  return q;
}

void queue_delete(Queue *q) {
  free(q->q);
  free(q);
}

inline static size_t queue_index(const Queue *q, size_t index) {
  return index % q->size;
}

size_t queue_size(const Queue *q) { return q->size; }

int queue_empty(const Queue *q) { return q->front == q->rear; }

int queue_full(const Queue *q) {
  return q->front == queue_index(q, q->rear + 1);
}

void queue_enqueue(Queue *q, int v) {
  if (queue_full(q)) {
    return;
  }
  q->q[q->rear] = v;
  q->rear = queue_index(q, q->rear + 1);
}

int queue_dequeue(Queue *q) {
  if (queue_empty(q)) {
    return -1;
  }
  int re = q->q[q->front];
  q->front = queue_index(q, q->front + 1);
  return re;
}

void queue_display(const Queue *q) {
  if (queue_empty(q)) {
    return;
  }
  size_t i = q->front;
  while (i != q->rear) {
    printf("%d ", q->q[i]);
    i = queue_index(q, i + 1);
  }
  printf("\n");
}
