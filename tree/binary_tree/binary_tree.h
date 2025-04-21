#pragma once

struct BinaryTree {
  struct BinaryTree *lchild;
  struct BinaryTree *rchild;
  int v;
};

typedef struct BinaryTree BinaryTree;
