#pragma once

#include <stddef.h>

struct DoubNode {
  int v;
  struct DoubNode *prev;
  struct DoubNode *next;
};

typedef struct DoubNode DoubNode;

DoubNode *doubnode_list_new(const int arr[], size_t size);

DoubNode *doubnode_new(int v);

void doubnode_delete(DoubNode *node);

void doubnode_list_delete(DoubNode *head);

void doubnode_display(const DoubNode *head);

size_t doubnode_size(const DoubNode *head);

void doubnode_insert(DoubNode **head, DoubNode *new_node, size_t index);

int doubnode_delete_from_list(DoubNode **head, size_t index);

DoubNode *doubnode_index(const DoubNode *head, size_t index);

DoubNode *doubnode_last(const DoubNode *head);
