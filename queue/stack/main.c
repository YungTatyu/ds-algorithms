#include "queue.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Queue *q = queue_new();
  for (int i = 0; i < 10; ++i) {
    queue_enqueue(q, i);
  }
  for (int i = 0; i < 5; ++i) {
    printf("%d ", queue_dequeue(q));
  }
  for (int i = 10; i < 20; ++i) {
    queue_enqueue(q, i);
  }
  for (int i = 0; i < 20; ++i) {
    printf("%d ", queue_dequeue(q));
  }
  return 0;
}
