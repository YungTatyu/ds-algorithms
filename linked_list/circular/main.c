#include "cir_node.h"

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  CirNode *list1 = cirnode_list_new(arr, sizeof(arr) / sizeof(int));
  cirnode_display(list1);
  cirnode_recur_display(list1, list1);
  return 0;
}
