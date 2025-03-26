#pragma once

#include <stddef.h>

struct CirNode {
  int v;
  struct CirNode *next;
};

typedef struct CirNode CirNode;

CirNode *cirnode_list_new(const int arr[], size_t size);

CirNode *cirnode_new(int v);

void cirnode_delete(CirNode *node);

void cirnode_list_delete(CirNode *head);

void cirnode_display(const CirNode *head);

void cirnode_recur_display(const CirNode *head, const CirNode *node);

CirNode *cirnode_index(const CirNode *head, size_t index);

CirNode *cirnode_last(const CirNode *head);

void cirnode_insert(CirNode **head, CirNode *new_node, size_t index);

size_t cirnode_size(const CirNode *head);
