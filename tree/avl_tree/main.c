#include "avl_tree.h"

int main(int argc, char *argv[]) {
  AvlNode *root = avl_recur_insert(NULL, 10);
  root = avl_recur_insert(root, 20);
  root = avl_recur_insert(root, 30);
  root = avl_recur_insert(root, 25);
  root = avl_recur_insert(root, 28);
  root = avl_recur_insert(root, 27);
  root = avl_recur_insert(root, 5);
  return 0;
}
