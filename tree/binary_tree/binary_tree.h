#pragma once

#include <stddef.h>

struct BinaryTreeNode {
  struct BinaryTreeNode *lchild;
  struct BinaryTreeNode *rchild;
  int v;
};

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode *binary_tree_new(int v);

void binary_tree_delete(BinaryTreeNode *root);

void binary_tree_preorder(BinaryTreeNode *node);

BinaryTreeNode *binary_tree_create(int *arr, size_t size);
