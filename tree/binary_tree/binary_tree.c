#include "binary_tree.h"
#include "queue.h"
#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

BinaryTreeNode *binary_tree_new(int v) {
  BinaryTreeNode *node = calloc(1, sizeof(BinaryTreeNode));
  if (node == NULL) {
    return NULL;
  }
  node->v = v;
  return node;
}

void binary_tree_delete(BinaryTreeNode *node) {
  if (node == NULL) {
    return;
  }
  binary_tree_delete(node->lchild);
  binary_tree_delete(node->rchild);
  free(node);
}

BinaryTreeNode *binary_tree_create(int *arr, size_t size) {
  if (size == 0) {
    return NULL;
  }
  Queue *q = queue_new();
  if (q == NULL) {
    return NULL;
  }
  BinaryTreeNode *root = binary_tree_new(arr[0]);
  if (root == NULL) {
    queue_delete(q);
    return NULL;
  }
  queue_enqueue(q, root);
  for (size_t i = 1; i < size; ++i) {
    BinaryTreeNode *parent = queue_front(q);
    BinaryTreeNode *child = binary_tree_new(arr[i]);
    if (child == NULL) {
      binary_tree_delete(root);
      queue_delete(q);
      return NULL;
    }
    if (i % 2 == 1) {
      parent->lchild = child;
    } else {
      parent->rchild = child;
      queue_dequeue(q);
    }
    queue_enqueue(q, child);
  }
  queue_delete(q);
  return root;
}

/**
 * Performs a preorder traversal of a binary tree.
 * The traversal order is: root -> left subtree -> right subtree.
 *
 * example:
 *
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 *
 * Preorder traversal order: 1 2 4 5 3
 * This function visits nodes in the order: root -> left -> right
 */
void binary_tree_recur_preorder(const BinaryTreeNode *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->v);
  binary_tree_recur_preorder(node->lchild);
  binary_tree_recur_preorder(node->rchild);
}

void binary_tree_recur_inorder(const BinaryTreeNode *node) {
  if (node == NULL) {
    return;
  }
  binary_tree_recur_inorder(node->lchild);
  printf("%d ", node->v);
  binary_tree_recur_inorder(node->rchild);
}

void binary_tree_recur_postorder(const BinaryTreeNode *node) {
  if (node == NULL) {
    return;
  }
  binary_tree_recur_postorder(node->lchild);
  binary_tree_recur_postorder(node->rchild);
  printf("%d ", node->v);
}

void binary_tree_preorder(const BinaryTreeNode *root) {
  Stack *st = stack_new();
  if (st == NULL) {
    return;
  }
  while (root != NULL || !stack_empty(st)) {
    if (root != NULL) {
      printf("%d ", root->v);
      stack_push(st, (BinaryTreeNode *)root);
      root = root->lchild;
    } else {
      root = stack_pop(st)->rchild;
    }
  }
  printf("\n");
  stack_delete(st);
}

void binary_tree_inorder(const BinaryTreeNode *root) {
  Stack *st = stack_new();
  if (st == NULL) {
    return;
  }
  while (root != NULL || !stack_empty(st)) {
    if (root != NULL) {
      stack_push(st, (BinaryTreeNode *)root);
      root = root->lchild;
    } else {
      root = stack_pop(st);
      printf("%d ", root->v);
      root = root->rchild;
    }
  }
  printf("\n");
  stack_delete(st);
}

void binary_tree_levelorder(const BinaryTreeNode *root) {
  if (root == NULL) {
    return;
  }
  Queue *q = queue_new();
  queue_enqueue(q, (BinaryTreeNode *)root);
  printf("%d ", root->v);
  while (!queue_empty(q)) {
    BinaryTreeNode *node = queue_dequeue(q);
    if (node->lchild != NULL) {
      printf("%d ", node->lchild->v);
      queue_enqueue(q, node->lchild);
    }
    if (node->rchild != NULL) {
      printf("%d ", node->rchild->v);
      queue_enqueue(q, node->rchild);
    }
  }
  queue_dequeue(q);
  printf("\n");
}

size_t binary_tree_count_node(const BinaryTreeNode *node) {
  if (node == NULL) {
    return 0;
  }
  size_t left = binary_tree_count_node(node->lchild);
  size_t right = binary_tree_count_node(node->rchild);
  return left + right + 1;
}

/**
 * Counts the number of nodes in a binary tree that have exactly two children.
 *
 * A node has degree two if it has both a left and a right child.
 * This function performs a recursive traversal of the binary tree,
 * incrementing the count whenever it encounters a node with two children.
 *
 * @param node The root node of the binary tree (or subtree).
 * @return The number of nodes with exactly two children.
 */
size_t binary_tree_count_node_degree_two(const BinaryTreeNode *node) {
  if (node == NULL) {
    return 0;
  }
  size_t left = binary_tree_count_node_degree_two(node->lchild);
  size_t right = binary_tree_count_node_degree_two(node->rchild);
  if (node->lchild != NULL && node->rchild != NULL) {
    return left + right + 1;
  } else {
    return left + right;
  }
}

/**
 * Calculates the height (or depth) of a binary tree.
 *
 * The height of a binary tree is defined as the number of levels
 * from the root node down to the deepest leaf node. An empty tree
 * has a height of 0, and a tree with only one node (the root) has a height
 * of 1.
 *
 * This function recursively computes the height by finding the maximum
 * height of the left and right subtrees and adding 1 for the current level.
 *
 * @param node The root node of the binary tree (or subtree).
 * @return The height (number of levels) of the tree.
 */
size_t binary_tree_height(const BinaryTreeNode *node) {
  if (node == NULL) {
    return 0;
  }
  size_t left = binary_tree_height(node->lchild);
  size_t right = binary_tree_height(node->rchild);
  if (left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
}

size_t binary_tree_count_leaf_node(const BinaryTreeNode *node) {
  if (node == NULL) {
    return 0;
  }
  size_t left = binary_tree_count_leaf_node(node->lchild);
  size_t right = binary_tree_count_leaf_node(node->rchild);
  if (node->lchild == NULL && node->rchild == NULL) {
    return left + right + 1;
  } else {
    return left + right;
  }
}
