#pragma once

struct BinaryTreeNode {
  struct BinaryTreeNode *lchild;
  struct BinaryTreeNode *rchild;
  int v;
};

typedef struct BinaryTreeNode BinaryTreeNode;

void binary_tree_new();

void binary_tree_delete();
