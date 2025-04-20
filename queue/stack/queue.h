#pragma once

#include "stack.h"

struct Queue {
  Stack *s_in;
  Stack *s_out;
};

typedef struct Queue Queue;

Queue *queue_new();

void queue_delete(Queue *q);

void queue_enqueue(Queue *q, int v);

int queue_dequeue(Queue *q);

int queue_empty(const Queue *q);
