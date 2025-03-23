#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {1, 1, 2, 3, 4, 5};
  Node *head = node_list_new(arr, sizeof(arr) / sizeof(int));
  node_display(head);
  printf("%d\n", node_is_sorted(head));
  node_delete_from_list(&head, 0);
  node_display(head);
  node_delete_from_list(&head, 3);
  node_display(head);
  node_delete_from_list(&head, 3);
  node_display(head);
  node_list_delete(head);
  return 0;
}
