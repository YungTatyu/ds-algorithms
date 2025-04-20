#include "priority_queue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PriotiryQueue *pqueue_new(size_t size) {
  PriotiryQueue *q = calloc(1, sizeof(PriotiryQueue));
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

void pqueue_delete(PriotiryQueue *q) {
  free(q->q);
  free(q);
}

size_t pqueue_size(const PriotiryQueue *q) { return q->size; }

int pqueue_empty(const PriotiryQueue *q) {
  return q->front == 0 && q->rear == 0;
}

int pqueue_full(const PriotiryQueue *q) { return q->rear == q->size; }

void pqueue_enqueue(PriotiryQueue *q, int v) {
  if (pqueue_full(q)) {
    return;
  }
  size_t i = q->front;
  while (i < q->rear) {
    if (v > q->q[i]) {
      break;
    }
    i++;
  }
  memmove(&q->q[i + 1], &q->q[i], (q->rear - i) * sizeof(int));
  q->q[i] = v;
  ++(q->rear);
}

int pqueue_dequeue(PriotiryQueue *q) {
  if (pqueue_empty(q)) {
    return -1;
  }
  int re = q->q[q->front];
  // queue is empty so reset
  if (q->front == q->rear - 1) {
    q->front = 0;
    q->rear = 0;
    return re;
  }
  ++(q->front);
  return re;
}

void pqueue_display(const PriotiryQueue *q) {
  if (pqueue_empty(q)) {
    return;
  }
  for (size_t i = q->front; i <= q->rear - 1; ++i) {
    printf("%d ", q->q[i]);
  }
  printf("\n");
}
