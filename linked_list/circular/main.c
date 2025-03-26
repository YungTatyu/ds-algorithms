#include "cir_node.h"

int main(int argc, char *argv[]) {
  // int arr[] = {1};
  int arr[] = {1, 2, 3, 4, 5};
  CirNode *list1 = cirnode_list_new(arr, sizeof(arr) / sizeof(int));
  // CirNode *list1 = NULL;
  cirnode_display(list1);
  cirnode_delete_from_list(&list1, 0);
  cirnode_recur_display(list1, list1);
  cirnode_delete_from_list(&list1, 3);
  cirnode_display(list1);
  cirnode_delete_from_list(&list1, 2);
  cirnode_display(list1);
  cirnode_delete_from_list(&list1, 1);
  cirnode_display(list1);
  cirnode_delete_from_list(&list1, 0);
  cirnode_display(list1);
  return 0;
}
