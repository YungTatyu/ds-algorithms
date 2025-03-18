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
  printf("search: %x\n", node_search(head, 4));
  printf("search: %x\n", node_recur_search(head, 6));
  printf("fast search: %x\n", node_search_with_move_front(&head, 1));
  printf("fast search: %x\n", node_search_with_move_front(&head, 4));
  node_recur_display(head);
  node_list_delete(head);
  return 0;
}
