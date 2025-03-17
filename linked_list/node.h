#pragma once

#include <stddef.h>

struct Node {
  int v;
  struct Node *next;
};

typedef struct Node Node;

Node *node_new(int v);

Node *node_list_new(const int *arr, size_t size);

void node_delete(Node *node);

void node_list_delete(Node *head);

void node_display(const Node *head);

void node_recur_display(const Node *head);
