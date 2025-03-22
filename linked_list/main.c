#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  Node *head = node_list_new(arr, sizeof(arr) / sizeof(int));
  node_display(head);
  printf("\n");
  node_insert(&head, 0, node_new(24));
  node_insert(&head, 6, node_new(42));
  node_display(head);
  node_list_delete(head);
  return 0;
}
