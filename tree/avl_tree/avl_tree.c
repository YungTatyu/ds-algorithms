#include "avl_tree.h"
#include <stddef.h>
#include <stdlib.h>

AvlNode *avl_new(int v) {
  AvlNode *node = calloc(1, sizeof(AvlNode));
  if (node == NULL) {
    return NULL;
  }
  node->v = v;
  node->height = 1; // height starting from 1
  return node;
}

void avl_delete(AvlNode *root) {
  if (root == NULL) {
    return;
  }
  avl_delete(root->lchild);
  avl_delete(root->rchild);
  free(root);
}

AvlNode *avl_recur_insert(AvlNode *node, int v) {
  if (node == NULL) {
    return avl_new(v);
  }
  if (v < node->v) {
    node->lchild = avl_recur_insert(node->lchild, v);
  } else if (v > node->v) {
    node->rchild = avl_recur_insert(node->rchild, v);
  }
  node->height = avl_height_node(node);

  long bf = avl_balance_factor(node);
  long lbf = avl_balance_factor(node->lchild);
  if (bf > 1 && lbf == 1) {
    return avl_llrotation(node);
  } // } else if (bf > 1 && lbf == -1) {
  //   return avl_lrrotation(node);
  // } else if (bf < -1 && lbf == 1) {
  //   return avl_rlrotation(node);
  // } else if (bf < -1 && lbf == -1) {
  //   return avl_rrrotation(node);
  // }
  return node;
}

size_t avl_height_node(const AvlNode *node) {
  size_t left = node != NULL && node->lchild != NULL ? node->lchild->height : 0;
  size_t right =
      node != NULL && node->rchild != NULL ? node->rchild->height : 0;
  return left > right ? left + 1 : right + 1;
}

/**
 * Calculates the balance factor of a given AVL tree node.
 *
 * The balance factor is defined as the height of the left subtree
 * minus the height of the right subtree. A balance factor of -1, 0,
 * or 1 indicates that the node is balanced.
 *
 * - A positive balance factor (> 0) means the left subtree is taller.
 * - A negative balance factor (< 0) means the right subtree is taller.
 * - A balance factor of 0 means both subtrees have the same height.
 *
 * If the node is NULL, its balance factor is considered 0.
 *
 * @param node A pointer to the AVL tree node.
 * @return The balance factor (left subtree height - right subtree height).
 */
long avl_balance_factor(const AvlNode *node) {
  long left = node != NULL && node->lchild != NULL ? node->lchild->height : 0;
  long right = node != NULL && node->rchild != NULL ? node->rchild->height : 0;
  return left - right;
}

AvlNode *avl_llrotation(AvlNode *node) {
  AvlNode *left = node->lchild;
  AvlNode *left_to_right = left->rchild;
  left->rchild = node;
  node->lchild = left_to_right;
  node->height = avl_height_node(node);
  left->height = avl_height_node(left);
  return left;
}
