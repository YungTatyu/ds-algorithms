#include "queue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Queue *queue_new() {
  Queue *q = calloc(1, sizeof(Queue));
  if (q == NULL) {
    return NULL;
  }
  return q;
}

void queue_delete(Queue *q) {
  while (q->front != NULL) {
    QueueNode *tmp = q->front->next;
    free(q->front);
    q->front = tmp;
  }
  free(q);
}

int queue_empty(const Queue *q) { return q->front == NULL; }

void queue_enqueue(Queue *q, int v) {
  QueueNode *node = calloc(1, sizeof(QueueNode));
  if (node == NULL) {
    return;
  }
  node->v = v;
  if (queue_empty(q)) {
    q->front = q->rear = node;
    return;
  }
  q->rear->next = node;
  q->rear = node;
}

int queue_dequeue(Queue *q) {
  if (queue_empty(q)) {
    return -1;
  }
  int re = q->front->v;
  QueueNode *next = q->front->next;
  free(q->front);
  q->front = next;
  return re;
}

void queue_display(const Queue *q) {
  if (queue_empty(q)) {
    return;
  }
  QueueNode *node = q->front;
  while (node != NULL) {
    printf("%d ", node->v);
    node = node->next;
  }
  printf("\n");
}
