#pragma once

#include <stddef.h>
struct BstNode {
  struct BstNode *lchild;
  struct BstNode *rchild;
  int v;
};

typedef struct BstNode BstNode;

BstNode *bst_new(int v);

void bst_delete(BstNode *root);

BstNode *bst_insert(BstNode *root, int v);

BstNode *bst_search(const BstNode *root, int key);

BstNode *bst_recur_insert(BstNode *node, int v);

BstNode *bst_recur_search(const BstNode *node, int v);

BstNode *bst_erase(BstNode *root, int key);

void bst_inorder(const BstNode *root);

BstNode *bst_inorder_predecessor(const BstNode *node);

BstNode *bst_inorder_successor(const BstNode *node);

size_t bst_height(const BstNode *root);
