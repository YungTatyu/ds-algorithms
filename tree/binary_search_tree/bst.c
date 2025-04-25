#include "bst.h"
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
