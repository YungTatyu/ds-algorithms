#include "dequeue.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Dequeue *q = dequeue_new(10);
  dequeue_display(q);
  dequeue_push_front(q, 1);
  dequeue_display(q);
  dequeue_push_front(q, 2);
  dequeue_push_front(q, 3);
  dequeue_push_front(q, 4);
  dequeue_display(q);
  printf("%d\n", dequeue_pop_front(q));
  printf("%d\n", dequeue_pop_front(q));
  for (size_t i = 0; i <= 10; ++i) {
    dequeue_push_front(q, i);
    dequeue_display(q);
  }
  dequeue_display(q);
  return 0;
}
