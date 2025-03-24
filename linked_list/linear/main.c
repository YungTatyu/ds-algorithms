#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr1[] = {1, 5, 6, 8, 10};
  int arr2[] = {2, 3, 4, 7};
  // int arr[] = {1, 2};
  Node *head1 = node_list_new(arr1, sizeof(arr1) / sizeof(int));
  Node *head2 = node_list_new(arr2, sizeof(arr2) / sizeof(int));
  node_display(head1);
  node_display(head2);
  printf("%d\n", node_is_loop(head1));
  node_last(head1)->next = head1;
  node_last(head2)->next = head2;
  printf("%d\n", node_is_loop(head1));
  printf("%d\n", node_is_loop(head2));
  // node_list_delete(head1);
  // node_list_delete(head2);
  return 0;
}
