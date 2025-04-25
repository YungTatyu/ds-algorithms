#include "bst.h"
#include <stddef.h>

int main(int argc, char *argv[]) {
  BstNode *root = bst_insert(NULL, 2);
  bst_insert(root, 1);
  bst_insert(root, 3);
  bst_inorder(root);

  return 0;
}
