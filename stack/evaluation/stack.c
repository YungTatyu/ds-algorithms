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
