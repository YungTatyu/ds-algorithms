#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {1, 1, 1, 2, 3, 3, 3, 4, 5, 5, 5};
  Node *head = node_list_new(arr, sizeof(arr) / sizeof(int));
  node_display(head);
  node_remove_duplicate(head);
  node_display(head);
  node_list_delete(head);
  return 0;
}
