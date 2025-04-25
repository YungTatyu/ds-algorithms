#include "binary_tree.h"

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  BinaryTreeNode *root = binary_tree_create(arr, sizeof(arr) / sizeof(int));
  binary_tree_levelorder(root);
  binary_tree_preorder(root);
  binary_tree_recur_preorder(root);

  binary_tree_inorder(root);
  binary_tree_recur_inorder(root);

  binary_tree_recur_postorder(root);
  binary_tree_delete(root);
  return 0;
}
