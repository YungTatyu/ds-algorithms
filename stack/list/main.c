#include "stack.h"

int main(int argc, char *argv[]) {

  Stack *st = stack_new();
  stack_push(st, 1);
  stack_push(st, 2);
  stack_push(st, 3);
  stack_display(st);
  stack_pop(st);
  stack_display(st);
  stack_pop(st);
  stack_display(st);
  stack_pop(st);
  stack_display(st);
  stack_pop(st);

  return 0;
}
