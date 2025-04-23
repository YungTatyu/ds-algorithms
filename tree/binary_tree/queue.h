#pragma once

#include <stddef.h>

typedef struct BinaryTreeNode BinaryTreeNode;

struct QueueNode {
  struct BinaryTreeNode *node;
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

void queue_enqueue(Queue *q, BinaryTreeNode *node);

BinaryTreeNode *queue_dequeue(Queue *q);

int queue_empty(const Queue *q);
