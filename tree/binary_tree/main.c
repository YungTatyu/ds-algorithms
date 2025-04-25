#include "binary_tree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  BinaryTreeNode *root = binary_tree_create(arr, sizeof(arr) / sizeof(int));
  printf("%zu\n", binary_tree_count_node(root));
  printf("%zu\n", binary_tree_count_node_degree_two(root));
  printf("%zu\n", binary_tree_count_node_degree_one(root));
  printf("%zu\n", binary_tree_height(root));
  printf("%zu\n", binary_tree_count_leaf_node(root));
  binary_tree_levelorder(root);
  binary_tree_preorder(root);
  binary_tree_recur_preorder(root);

  binary_tree_inorder(root);
  binary_tree_recur_inorder(root);

  binary_tree_recur_postorder(root);
  binary_tree_delete(root);
  return 0;
}
