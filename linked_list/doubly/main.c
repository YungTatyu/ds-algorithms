#include "doub_node.h"

int main(int argc, char *argv[]) {
  // int arr[] = {1, 2, 3, 4, 5};
  int arr[] = {1};
  // DoubNode *list1 = doubnode_list_new(arr, sizeof(arr) / sizeof(int));
  DoubNode *list1 = NULL;
  doubnode_display(list1);
  doubnode_reverse(&list1);
  doubnode_display(list1);
  return 0;
}
