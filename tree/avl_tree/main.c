#include "avl_tree.h"

int main(int argc, char *argv[]) {
  AvlNode *root = avl_recur_insert(NULL, 10);
  root = avl_recur_insert(root, 20);
  root = avl_recur_insert(root, 30);
  root = avl_recur_insert(root, 25);
  root = avl_recur_insert(root, 28);
  root = avl_recur_insert(root, 27);
  root = avl_recur_insert(root, 5);
  root = avl_recur_insert(root, 50);
  root = avl_recur_insert(root, 100);
  root = avl_recur_insert(root, 200);
  root = avl_recur_insert(root, 300);
  root = avl_recur_insert(root, 400);
  root = avl_recur_erase(root, 25);
  return 0;
}
