#pragma once

#include <stddef.h>
#include <unistd.h>

struct Stack {
  size_t size;
  ssize_t top;
  int *s;
};

typedef struct Stack Stack;

Stack *stack_new(size_t size);

void stack_delete(Stack *st);

void stack_display(const Stack *st);

int stack_full(const Stack *st);

int stack_empty(const Stack *st);

void stack_push(Stack *st, int v);

int stack_pop(Stack *st);

int stack_peek(const Stack *st, size_t index);

int stack_top(const Stack *st);
