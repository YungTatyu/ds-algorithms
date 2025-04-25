#pragma once

#include <stddef.h>

typedef struct BinaryTreeNode BinaryTreeNode;

struct StackNode {
  struct BinaryTreeNode *node;
  struct StackNode *next;
};

typedef struct StackNode StackNode;

struct Stack {
  StackNode *top;
};

typedef struct Stack Stack;

Stack *stack_new();

void stack_delete(Stack *st);

void stack_push(Stack *st, BinaryTreeNode *node);

BinaryTreeNode *stack_pop(Stack *st);

int stack_empty(const Stack *st);

BinaryTreeNode *stack_top(const Stack *st);

size_t stack_size(const Stack *st);
