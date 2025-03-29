#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Stack *stack_new(size_t size) {
  Stack *st = calloc(1, sizeof(Stack));
  if (st == NULL) {
    return NULL;
  }
  st->size = size;
  st->top = -1;
  st->s = calloc(size, sizeof(int));
  if (st->s == NULL) {
    free(st);
    return NULL;
  }
  return st;
}

void stack_delete(Stack *st) {
  free(st->s);
  free(st);
}

void stack_display(const Stack *st) {
  for (ssize_t i = st->top; i >= 0; --i) {
    printf("%d ", st->s[i]);
  }
  printf("\n");
}

int stack_full(const Stack *st) { return st->top == st->size - 1; }

int stack_empty(const Stack *st) { return st->top == -1; }

void stack_push(Stack *st, int v) {
  if (stack_full(st)) {
    return;
  }
  ++(st->top);
  st->s[st->top] = v;
}

int stack_pop(Stack *st) {
  if (stack_empty(st)) {
    return -1;
  }
  int v = st->s[st->top];
  --(st->top);
  return v;
}
