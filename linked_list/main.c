#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  Node *head = node_list_new(arr, sizeof(arr) / sizeof(int));
  node_display(head);
  node_recur_display(head);
  printf("\n");
  printf("size: %zu\n", node_size(head));
  printf("size: %zu\n", node_recur_size(head));
  printf("sum: %d\n", node_sum(head));
  printf("sum: %d\n", node_recur_sum(head));
  printf("max: %d\n", node_max(head));
  printf("max: %d\n", node_recur_max(head));
  node_list_delete(head);
  return 0;
}
