#pragma once

#include <stddef.h>

struct AvlNode {
  struct AvlNode *lchild;
  struct AvlNode *rchild;
  int v;
  size_t height;
};

typedef struct AvlNode AvlNode;

AvlNode *avl_new(int v);

void avl_delete(AvlNode *root);

AvlNode *avl_recur_insert(AvlNode *node, int v);

size_t avl_height_node(const AvlNode *node);

long avl_balance_factor(const AvlNode *node);
