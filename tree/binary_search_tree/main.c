#include "bst.h"
#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // BstNode *root = bst_insert(NULL, 20);
  // bst_insert(root, 10);
  // bst_insert(root, 30);
  // bst_insert(root, 15);
  // bst_insert(root, 21);
  // bst_insert(root, 31);
  // bst_insert(root, 41);
  BstNode *root = bst_recur_insert(NULL, 20);
  bst_recur_insert(root, 10);
  bst_recur_insert(root, 30);
  bst_recur_insert(root, 15);
  bst_recur_insert(root, 21);
  bst_recur_insert(root, 31);
  bst_recur_insert(root, 41);
  printf("%x\n", bst_search(root, 10));
  printf("%x\n", bst_search(root, 0));
  printf("%x\n", bst_search(root, 41));
  printf("%x\n", bst_recur_search(root, 10));
  printf("%x\n", bst_recur_search(root, 0));
  printf("%x\n", bst_recur_search(root, 41));
  bst_inorder(root);

  return 0;
}
