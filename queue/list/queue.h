#pragma once

#include <stddef.h>

struct QueueNode {
  int v;
  struct QueueNode *next;
};

typedef struct QueueNode QueueNode;

struct Queue {
  QueueNode *front;
  QueueNode *rear;
};

typedef struct Queue Queue;

Queue *queue_new();

void queue_delete(Queue *q);

void queue_enqueue(Queue *q, int v);

int queue_dequeue(Queue *q);

int queue_empty(const Queue *q);

void queue_display(const Queue *q);
