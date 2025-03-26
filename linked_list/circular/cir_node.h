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
