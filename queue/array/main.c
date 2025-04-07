#include "queue.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Queue *q = queue_new(10);
  queue_display(q);
  queue_enqueue(q, 1);
  queue_display(q);
  queue_enqueue(q, 2);
  queue_enqueue(q, 3);
  queue_enqueue(q, 4);
  queue_display(q);
  printf("%d ", queue_dequeue(q));
  printf("%d ", queue_dequeue(q));
  for (size_t i = 0; i <= 10; ++i) {
    queue_enqueue(q, i);
    queue_display(q);
  }
  queue_display(q);
  return 0;
}
