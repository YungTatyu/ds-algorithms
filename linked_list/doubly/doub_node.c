#include "doub_node.h"
#include <stdio.h>
#include <stdlib.h>

DoubNode *doubnode_new(int v) {
  DoubNode *n = calloc(1, sizeof(DoubNode));
  if (n == NULL) {
    return NULL;
  }
  n->v = v;
  return n;
}

DoubNode *doubnode_list_new(const int arr[], size_t size) {
  DoubNode *head = NULL;
  DoubNode *tail = NULL;
  for (size_t i = 0; i < size; ++i) {
    DoubNode *new_node = doubnode_new(arr[i]);
    if (new_node == NULL) {
      doubnode_list_delete(head);
      return NULL;
    }
    if (head == NULL) {
      head = new_node;
    } else {
      tail->next = new_node;
      new_node->prev = tail;
    }
    tail = new_node;
  }
  return head;
}

void doubnode_delete(DoubNode *node) { free(node); }

void doubnode_list_delete(DoubNode *head) {
  while (head != NULL) {
    DoubNode *tmp = head->next;
    doubnode_delete(head);
    head = tmp;
  }
}

void doubnode_display(const DoubNode *head) {
  while (head != NULL) {
    printf("%d ", head->v);
    head = head->next;
  }
  printf("\n");
}

size_t doubnode_size(const DoubNode *head) {
  size_t size = 0;
  while (head != NULL) {
    ++size;
    head = head->next;
  }
  return size;
}
