#pragma once

#include <stddef.h>

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

size_t stack_size(const Stack *st);
