#include "doub_node.h"

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  // int arr[] = {1};
  DoubNode *list1 = doubnode_list_new(arr, sizeof(arr) / sizeof(int));
  // DoubNode *list1 = NULL;
  doubnode_display(list1);
  doubnode_insert(&list1, doubnode_new(24), 0);
  doubnode_insert(&list1, doubnode_new(2), 1);
  doubnode_display(list1);
  doubnode_delete_from_list(&list1, 1);
  doubnode_delete_from_list(&list1, 3);
  doubnode_display(list1);
  doubnode_delete_from_list(&list1, 0);
  doubnode_display(list1);
  return 0;
}
