#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  Node *head = node_list_new(arr, sizeof(arr) / sizeof(int));
  node_display(head);
  printf("\n");
  node_sorted_insert(&head, node_new(42));
  node_sorted_insert(&head, node_new(0));
  node_display(head);
  node_list_delete(head);
  return 0;
}
