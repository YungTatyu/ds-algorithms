#include "avl_tree.h"
#include <stdlib.h>

AvlNode *avl_new(int v) {
  AvlNode *node = calloc(1, sizeof(AvlNode));
  if (node == NULL) {
    return NULL;
  }
  node->v = v;
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
