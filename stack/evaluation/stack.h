#pragma once

struct CStackNode {
  char v;
  struct CStackNode *next;
};

typedef struct CStackNode CStackNode;

struct CStack {
  CStackNode *top;
};

typedef struct CStack CStack;

CStack *cstack_new();

void cstack_delete(CStack *st);

void cstack_push(CStack *st, char v);

char cstack_pop(CStack *st);

void cstack_display(const CStack *st);

char cstack_empty(const CStack *st);

char cstack_top(const CStack *st);
