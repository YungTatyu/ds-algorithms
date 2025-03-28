#pragma once

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
