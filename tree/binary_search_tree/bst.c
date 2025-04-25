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
  return node;
}

void bst_inorder(const BstNode *root) {
  if (root == NULL) {
    return;
  }
  bst_inorder(root->lchild);
  printf("%d ", root->v);
  bst_inorder(root->rchild);
}
