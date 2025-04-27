#include "avl_tree.h"

int main(int argc, char *argv[]) {
  AvlNode *root = avl_recur_insert(NULL, 10);
  root = avl_recur_insert(root, 5);
  root = avl_recur_insert(root, 2);
  return 0;
}
