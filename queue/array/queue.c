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

size_t queue_size(const Queue *q) { return q->size; }

int queue_empty(const Queue *q) { return q->front == 0 && q->rear == 0; }

int queue_full(const Queue *q) { return q->rear == q->size; }

void queue_enqueue(Queue *q, int v) {
  if (queue_full(q)) {
    return;
  }
  q->q[q->rear] = v;
  ++(q->rear);
}

int queue_dequeue(Queue *q) {
  if (queue_empty(q)) {
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

void queue_display(const Queue *q) {
  if (queue_empty(q)) {
    return;
  }
  for (size_t i = q->front; i <= q->rear - 1; ++i) {
    printf("%d ", q->q[i]);
  }
  printf("\n");
}
