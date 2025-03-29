#include "stack.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Stack *st = stack_new(3);
  stack_display(st);
  stack_push(st, 1);
  stack_push(st, 2);
  stack_push(st, 3);
  stack_display(st);
  stack_push(st, 4);
  printf("%d ", stack_peek(st, 0));
  printf("%d ", stack_top(st));
  printf("%d ", stack_peek(st, 1));
  printf("%d ", stack_peek(st, 2));
  printf("%d ", stack_peek(st, 3));
  printf("%d ", stack_pop(st));
  printf("%d ", stack_pop(st));
  // printf("%d ", stack_pop(st));
  printf("%d ", stack_top(st));
  // stack_display(st);

  return 0;
}
