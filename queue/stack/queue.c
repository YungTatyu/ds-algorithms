#include "queue.h"
#include "stack.h"
#include <stdlib.h>

Queue *queue_new() {
  Queue *q = calloc(1, sizeof(Queue));
  if (q == NULL) {
    return NULL;
  }
  q->s_in = stack_new();
  q->s_out = stack_new();
  if (q->s_in == NULL || q->s_out == NULL) {
    stack_delete(q->s_in);
    stack_delete(q->s_out);
    free(q);
    return NULL;
  }
  return q;
}

void queue_delete(Queue *q) {
  stack_delete(q->s_in);
  stack_delete(q->s_out);
  free(q);
}

void queue_enqueue(Queue *q, int v) { stack_push(q->s_in, v); }

int queue_dequeue(Queue *q) {
  if (queue_empty(q)) {
    return -1;
  }
  if (stack_empty(q->s_out)) {
    while (!stack_empty(q->s_in)) {
      stack_push(q->s_out, stack_pop(q->s_in));
    }
  }
  return stack_pop(q->s_out);
}

int queue_empty(const Queue *q) {
  return stack_empty(q->s_in) && stack_empty(q->s_out);
}
