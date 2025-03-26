#include "doub_node.h"

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  DoubNode *list1 = doubnode_list_new(arr, sizeof(arr) / sizeof(int));
  doubnode_display(list1);
  return 0;
}
