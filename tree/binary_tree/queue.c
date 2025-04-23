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

int queue_empty(const Queue *q) { return q->front == NULL; }

void queue_enqueue(Queue *q, BinaryTreeNode *b_node) {
  QueueNode *node = calloc(1, sizeof(QueueNode));
  if (node == NULL) {
    return;
  }
  node->node = b_node;
  if (queue_empty(q)) {
    q->front = q->rear = node;
    return;
  }
  q->rear->next = node;
  q->rear = node;
}

BinaryTreeNode *queue_dequeue(Queue *q) {
  if (queue_empty(q)) {
    return NULL;
  }
  BinaryTreeNode *re = q->front->node;
  QueueNode *next = q->front->next;
  // free(q->front);
  q->front = next;
  return re;
}
