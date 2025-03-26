#include "cir_node.h"
#include <stdlib.h>

CirNode *cirnode_new(int v) {
  CirNode *n = calloc(1, sizeof(CirNode));
  if (n == NULL) {
    return NULL;
  }
  n->v = v;
  n->next = n;
  return n;
}

CirNode *cirnode_list_new(const int arr[], size_t size) {

  CirNode *head = NULL;
  CirNode *tail;
  for (size_t i = 0; i < size; ++i) {
    CirNode *new_node = cirnode_new(arr[i]);
    if (new_node == NULL) {
      cirnode_list_delete(head);
      return NULL;
    }
    if (head == NULL) {
      head = new_node;
    } else {
      tail->next = new_node;
    }
    tail = new_node;
  }
  tail->next = head;
  return head;
}

void cirnode_delete(CirNode *node) { free(node); }

void cirnode_list_delete(CirNode *head) {
  CirNode *node = head;
  do {
    CirNode *tmp = node->next;
    cirnode_delete(node);
    node = tmp;
  } while (node != head);
}
