#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  // int arr[] = {1, 2, 3, 4, 5};
  int arr[] = {1};
  Node *head = node_list_new(arr, sizeof(arr) / sizeof(int));
  node_display(head);
  node_reverse_with_array(head);
  node_display(head);
  node_list_delete(head);
  return 0;
}
