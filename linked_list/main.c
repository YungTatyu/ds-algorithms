#include "node.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {6, 7, 8, 9, 10};
  // int arr[] = {1, 2};
  Node *head1 = node_list_new(arr1, sizeof(arr1) / sizeof(int));
  Node *head2 = node_list_new(arr2, sizeof(arr2) / sizeof(int));
  node_display(head1);
  node_concat(head1, head2);
  node_display(head1);
  node_list_delete(head1);
  // node_list_delete(head2);
  return 0;
}
