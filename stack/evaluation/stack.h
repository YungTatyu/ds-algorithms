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

struct StackNode {
  int v;
  struct StackNode *next;
};

typedef struct StackNode StackNode;

struct Stack {
  StackNode *top;
};

typedef struct Stack Stack;

Stack *stack_new();

void stack_delete(Stack *st);

void stack_push(Stack *st, int v);

int stack_pop(Stack *st);

void stack_display(const Stack *st);

int stack_empty(const Stack *st);

int stack_top(const Stack *st);
