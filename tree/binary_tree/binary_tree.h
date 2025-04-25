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

BinaryTreeNode *binary_tree_create(int *arr, size_t size);

void binary_tree_preorder(const BinaryTreeNode *root);

void binary_tree_inorder(const BinaryTreeNode *root);

void binary_tree_postorder(const BinaryTreeNode *root);

void binary_tree_recur_preorder(const BinaryTreeNode *node);

void binary_tree_recur_inorder(const BinaryTreeNode *node);

void binary_tree_recur_postorder(const BinaryTreeNode *node);
