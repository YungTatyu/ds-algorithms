#include "priority_queue.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  PriotiryQueue *q = pqueue_new(10);
  // pqueue_display(q);
  // pqueue_enqueue(q, 2);
  // pqueue_enqueue(q, 3);
  // pqueue_enqueue(q, 4);
  // pqueue_display(q);
  printf("%d ", pqueue_dequeue(q));
  printf("%d\n", pqueue_dequeue(q));
  for (size_t i = 0; i <= 10; ++i) {
    pqueue_enqueue(q, i);
    pqueue_display(q);
  }
  for (size_t i = 0; i <= 10; ++i) {
    printf("%d ", pqueue_dequeue(q));
  }
  pqueue_display(q);
  return 0;
}
