#include "dequeue.h"
#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  Dequeue *q = dequeue_new(12);
  size_t i = 0;
  while (i <= 10) {
    dequeue_push_front(q, i++);
    dequeue_push_back(q, i++);
    dequeue_display(q);
  }
  dequeue_display(q);
  while (!dequeue_empty(q)) {
    printf("pop front: %d\n", dequeue_pop_front(q));
    printf("pop back : %d\n", dequeue_pop_back(q));
    dequeue_display(q);
  }
  dequeue_display(q);
  return 0;
}
