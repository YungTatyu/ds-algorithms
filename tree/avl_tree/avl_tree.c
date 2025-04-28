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
  } else if (bf > 1 && lbf == -1) {
    return avl_lrrotation(node);
  } else if (bf < -1 && lbf == 1) {
    return avl_rlrotation(node);
  } else if (bf < -1 && lbf == -1) {
    return avl_rrrotation(node);
  }
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

/**
 * Performs a left-left (LL) rotation on the given AVL tree node.
 *
 * LL rotation is used to fix an imbalance where a node's left child
 * is taller, and that left child also has a taller left subtree
 * (causing a heavy tilt to the left).
 *
 * After rotation:
 * - The left child becomes the new root of the subtree.
 * - The original root becomes the right child of the new root.
 * - The affected nodes' heights are updated.
 *
 * Simple diagram for LL rotation:
 *
 *     Before rotation:                   After rotation:
 *         node                                left
 *         /                                   /   \
 *      left       =>                     left_left  node
 *      /    \                                        /    \
 *  left_left left_right                    left_right  right_child
 *
 * (`right_child` represents the original right child of `node`, if any.)
 *
 * @param node A pointer to the root of the unbalanced subtree.
 * @return A pointer to the new root of the subtree after rotation.
 */
AvlNode *avl_llrotation(AvlNode *node) {
  AvlNode *left = node->lchild;
  AvlNode *left_to_right = left->rchild;
  left->rchild = node;
  node->lchild = left_to_right;

  node->height = avl_height_node(node);
  left->height = avl_height_node(left);
  return left;
}

/**
 * Performs a left-right (LR) double rotation on the given AVL tree node.
 *
 * LR rotation is used to fix an imbalance where a node's left child
 * is taller, but that left child itself has a taller right subtree
 * (causing a left-right tilt).
 *
 * The LR rotation consists of two steps:
 * 1. Perform a left rotation on the left child.
 * 2. Perform a right rotation on the node itself.
 *
 * After rotation:
 * - The left child's right child (`left_right`) becomes the new root of the
 * subtree.
 * - The original left child becomes the left child of `left_right`.
 * - The original node becomes the right child of `left_right`.
 * - Heights are updated appropriately.
 *
 * Simple diagram for LR rotation:
 *
 *     Before rotations:                     After rotations:
 *
 *         node                                    left_to_right
 *         /                                       /          \
 *      left       =>                         left            node
 *        \                                        \           /
 *      left_to_right                      left_to_rl     left_to_rr
 *       /        \
 * left_to_rl  left_to_rr
 *
 * (`left_left` and `right_child` are the original left and right subtrees of
 * `left` and `node` respectively, if they exist.)
 *
 * @param node A pointer to the root of the unbalanced subtree.
 * @return A pointer to the new root of the subtree after double rotation.
 */
AvlNode *avl_lrrotation(AvlNode *node) {
  AvlNode *left = node->lchild;
  AvlNode *left_to_right = left->rchild;
  node->lchild = left_to_right->rchild;
  left->rchild = left_to_right->lchild;
  left_to_right->lchild = left;
  left_to_right->rchild = node;

  left->height = avl_height_node(left);
  node->height = avl_height_node(node);
  left_to_right->height = avl_height_node(left_to_right);
  return left_to_right;
}

AvlNode *avl_rlrotation(AvlNode *node) {
  AvlNode *right = node->rchild;
  AvlNode *right_to_left = right->lchild;
  node->rchild = right_to_left->lchild;
  right->lchild = right_to_left->rchild;
  right_to_left->lchild = node;
  right_to_left->rchild = right;

  node->height = avl_height_node(node);
  right->height = avl_height_node(right);
  right_to_left->height = avl_height_node(right_to_left);
  return right_to_left;
}

AvlNode *avl_rrrotation(AvlNode *node) {
  AvlNode *right = node->rchild;
  AvlNode *right_to_left = right->lchild;
  node->rchild = right_to_left;
  right->lchild = node;

  node->height = avl_height_node(node);
  right->height = avl_height_node(right);
  return right;
}
