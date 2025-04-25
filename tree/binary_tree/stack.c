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

void stack_push(Stack *st, BinaryTreeNode *node) {
  StackNode *new_node = calloc(1, sizeof(StackNode));
  if (new_node == NULL) {
    return;
  }
  new_node->node = node;
  new_node->next = st->top;
  st->top = new_node;
}

BinaryTreeNode *stack_pop(Stack *st) {
  if (st->top == NULL) {
    return NULL;
  }
  StackNode *delete = st->top;
  st->top = st->top->next;
  BinaryTreeNode *v = delete->node;
  free(delete);
  return v;
}

int stack_empty(const Stack *st) { return st->top == NULL; }

BinaryTreeNode *stack_top(const Stack *st) {
  if (stack_empty(st)) {
    return NULL;
  }
  return st->top->node;
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
