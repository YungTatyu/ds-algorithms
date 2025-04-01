#pragma once

struct StackNode {
  char v;
  struct StackNode *next;
};

typedef struct StackNode StackNode;

struct Stack {
  StackNode *top;
};

typedef struct Stack Stack;

Stack *stack_new();

void stack_delete(Stack *st);

void stack_push(Stack *st, char v);

char stack_pop(Stack *st);

void stack_display(const Stack *st);

char stack_empty(const Stack *st);
