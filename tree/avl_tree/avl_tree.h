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

AvlNode *avl_insert(AvlNode *root, int key);
