#include "cir_node.h"

int main(int argc, char *argv[]) {
  int arr[] = {1};
  CirNode *list1 = cirnode_list_new(arr, sizeof(arr) / sizeof(int));
  // CirNode *list1 = NULL;
  // cirnode_display(list1);
  cirnode_insert(&list1, cirnode_new(24), 0);
  cirnode_recur_display(list1, list1);
  cirnode_insert(&list1, cirnode_new(42), 3);
  cirnode_display(list1);
  return 0;
}
