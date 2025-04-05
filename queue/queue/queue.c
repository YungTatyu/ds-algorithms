#include "queue.h"
#include <stddef.h>
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

int queue_full(const Queue *q) { return q->rear == q->size - 1; }
