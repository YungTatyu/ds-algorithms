#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BstNode *bst_new(int v) {
  BstNode *node = calloc(1, sizeof(BstNode));
  if (node == NULL) {
    return NULL;
  }
  node->v = v;
  return node;
}

void bst_delete(BstNode *root) {
  if (root == NULL) {
    return;
  }
  bst_delete(root->lchild);
  bst_delete(root->rchild);
  free(root);
}

BstNode *bst_insert(BstNode *root, int v) {
  if (root == NULL) {
    return bst_new(v);
  }
  BstNode *head, *tail;
  head = root;
  while (head != NULL) {
    tail = head;
    if (head->v == v) {
      return root;
    }
    if (v < head->v) {
      head = head->lchild;
    } else {
      head = head->rchild;
    }
  }
  BstNode *new_node = bst_new(v);
  if (new_node == NULL) {
    return NULL;
  }
  if (v < tail->v) {
    tail->lchild = new_node;
  } else {
    tail->rchild = new_node;
  }
  return root;
}

BstNode *bst_search(const BstNode *root, int key) {
  while (root != NULL) {
    if (root->v == key) {
      return (BstNode *)root;
    }
    if (key < root->v) {
      root = root->lchild;
    } else {
      root = root->rchild;
    }
  }
  return NULL;
}

BstNode *bst_recur_insert(BstNode *node, int v) {
  if (node == NULL) {
    return bst_new(v);
  }
  if (v < node->v) {
    node->lchild = bst_recur_insert(node->lchild, v);
  } else if (v > node->v) {
    node->rchild = bst_recur_insert(node->rchild, v);
  }
  return node;
}

BstNode *bst_recur_search(const BstNode *node, int v) {
  if (node == NULL) {
    return NULL;
  }
  if (v < node->v) {
    return bst_recur_search(node->lchild, v);
  } else if (v > node->v) {
    return bst_recur_search(node->rchild, v);
  }
  return (BstNode *)node;
}

BstNode *bst_erase(BstNode *root, int key) {
  if (root == NULL) {
    return NULL;
  }
  if (key < root->v) {
    root->lchild = bst_erase(root->lchild, key);
  } else if (key > root->v) {
    root->rchild = bst_erase(root->rchild, key);
  } else {
    // delete leaf node
    if (root->lchild == NULL && root->rchild == NULL) {
      free(root);
      return NULL;
    } else if (bst_height(root->lchild) > bst_height(root->rchild)) {
      BstNode *pre = bst_inorder_predecessor(root);
      root->v = pre->v;
      root->lchild = bst_erase(root->lchild, pre->v);
    } else {
      BstNode *post = bst_inorder_successor(root);
      root->v = post->v;
      root->rchild = bst_erase(root->rchild, post->v);
    }
  }
  return root;
}

void bst_inorder(const BstNode *root) {
  if (root == NULL) {
    return;
  }
  bst_inorder(root->lchild);
  printf("%d ", root->v);
  bst_inorder(root->rchild);
}

size_t bst_height(const BstNode *root) {
  if (root == NULL) {
    return 0;
  }
  size_t left = bst_height(root->lchild);
  size_t right = bst_height(root->rchild);
  return left > right ? left + 1 : right + 1;
}

/**
 * Returns the inorder predecessor of the given node in a binary search tree
 * (BST).
 *
 * The inorder predecessor of a node is the node that comes immediately before
 * the given node in the inorder traversal of the BST.
 *
 * If the node has a left child, the predecessor is the rightmost node in the
 * left subtree. If there is no left child, the predecessor must be found by
 * moving up the tree, which typically requires access to the parent pointer
 * (not handled here unless included).
 *
 * @param node A pointer to the node for which to find the inorder predecessor.
 * @return A pointer to the inorder predecessor node, or NULL if none exists.
 */
BstNode *bst_inorder_predecessor(const BstNode *node) {
  while (node != NULL && node->rchild != NULL) {
    node = node->rchild;
  }
  return (BstNode *)node;
}

/**
 * Returns the inorder successor of the given node in a binary search tree
 * (BST).
 *
 * The inorder successor of a node is the node that appears immediately after
 * the given node in an inorder traversal of the BST.
 *
 * If the node has a right child, the successor is the leftmost node in the
 * right subtree. If there is no right child, the successor would typically be
 * found by traversing up to the parent (not handled here unless the parent
 * pointer is available).
 *
 * @param node A pointer to the node for which to find the inorder successor.
 * @return A pointer to the inorder successor node, or NULL if none exists.
 */
BstNode *bst_inorder_successor(const BstNode *node) {
  while (node != NULL && node->lchild != NULL) {
    node = node->lchild;
  }
  return (BstNode *)node;
}
