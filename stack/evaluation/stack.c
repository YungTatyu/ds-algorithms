#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

CStack *cstack_new() {
  CStack *st = calloc(1, sizeof(CStack));
  return st;
}

void cstack_delete(CStack *st) {
  CStackNode *node = st->top;
  while (node != NULL) {
    CStackNode *tmp = node->next;
    free(node);
    node = node->next;
  }
  free(st);
}

void cstack_push(CStack *st, char v) {
  CStackNode *node = calloc(1, sizeof(CStackNode));
  if (node == NULL) {
    return;
  }
  node->v = v;
  node->next = st->top;
  st->top = node;
}

char cstack_pop(CStack *st) {
  if (st->top == NULL) {
    return -1;
  }
  CStackNode *delete = st->top;
  st->top = st->top->next;
  int v = delete->v;
  free(delete);
  return v;
}

void cstack_display(const CStack *st) {
  CStackNode *node = st->top;
  while (node != NULL) {
    printf("%d ", node->v);
    node = node->next;
  }
  printf("\n");
}

char cstack_empty(const CStack *st) { return st->top == NULL; }

char cstack_top(const CStack *st) {
  if (cstack_empty(st)) {
    return -1;
  }
  return st->top->v;
}

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
