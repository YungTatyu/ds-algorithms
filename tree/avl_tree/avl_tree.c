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
  return node;
}

size_t avl_height_node(const AvlNode *node) {
  size_t left = node != NULL && node->lchild != NULL ? node->lchild->height : 0;
  size_t right =
      node != NULL && node->rchild != NULL ? node->rchild->height : 0;
  return left > right ? left + 1 : right + 1;
}
