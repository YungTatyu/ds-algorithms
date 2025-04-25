#pragma once

struct BstNode {
  struct BstNode *lchild;
  struct BstNode *rchild;
  int v;
};

typedef struct BstNode BstNode;

BstNode *bst_new(int v);

BstNode *bst_delete(BstNode *root);

void bst_insert(BstNode *root, int v);
