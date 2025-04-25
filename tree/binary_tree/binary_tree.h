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

void binary_tree_levelorder(const BinaryTreeNode *root);

void binary_tree_recur_preorder(const BinaryTreeNode *node);

void binary_tree_recur_inorder(const BinaryTreeNode *node);

void binary_tree_recur_postorder(const BinaryTreeNode *node);

size_t binary_tree_count_node(const BinaryTreeNode *node);

size_t binary_tree_height(const BinaryTreeNode *node);

size_t binary_tree_count_node_degree_two(const BinaryTreeNode *node);

size_t binary_tree_count_node_degree_one(const BinaryTreeNode *node);

size_t binary_tree_count_leaf_node(const BinaryTreeNode *node);
