#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_new() {
  Stack *st = calloc(1, sizeof(Stack));
  return st;
}

void stack_delete(Stack *st) {
  StackNode *node = st->top;
  while (node != NULL) {
    StackNode *tmp = node->next;
    free(node);
    node = node->next;
  }
  free(st);
}

void stack_push(Stack *st, int v) {
  StackNode *node = calloc(1, sizeof(StackNode));
  if (node == NULL) {
    return;
  }
  node->v = v;
  node->next = st->top;
  st->top = node;
}

int stack_pop(Stack *st) {
  if (st->top == NULL) {
    return -1;
  }
  StackNode *delete = st->top;
  st->top = st->top->next;
  int v = delete->v;
  free(delete);
  return v;
}

void stack_display(const Stack *st) {
  StackNode *node = st->top;
  while (node != NULL) {
    printf("%d ", node->v);
    node = node->next;
  }
  printf("\n");
}

int stack_empty(const Stack *st) { return st->top == NULL; }

int stack_top(const Stack *st) {
  if (stack_empty(st)) {
    return -1;
  }
  return st->top->v;
}

size_t stack_size(const Stack *st) {
  size_t i = 0;
  StackNode *node = st->top;
  while (node != NULL) {
    ++i;
    node = node->next;
  }
  return i;
}
