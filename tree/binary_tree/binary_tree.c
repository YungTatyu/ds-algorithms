#include "binary_tree.h"
#include "queue.h"
#include "stack.h"
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
