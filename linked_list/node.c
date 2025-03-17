#include "node.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Node *node_new(int v) {
  Node *n = calloc(1, sizeof(Node));
  if (n == NULL) {
    return NULL;
  }
  n->v = v;
  return n;
}

Node *node_list_new(const int *arr, size_t size) {
  Node *head = NULL;
  Node *tail;
  for (size_t i = 0; i < size; ++i) {
    Node *new_node = node_new(arr[i]);
    if (new_node == NULL) {
      node_list_delete(head);
      return NULL;
    }
    if (head == NULL) {
      head = new_node;
    } else {
      tail->next = new_node;
    }
    tail = new_node;
  }
  return head;
}

void node_delete(Node *node) { free(node); }

void node_list_delete(Node *head) {
  while (head != NULL) {
    Node *next = head->next;
    node_delete(head);
    head = next;
  }
}

void node_display(const Node *head) {
  const Node *node = head;
  while (node != NULL) {
    printf("%d ", node->v);
    node = node->next;
  }
}

void node_recur_display(const Node *head) {
  if (head == NULL) {
    return;
  }
  printf("%d ", head->v);
  node_recur_display(head->next);
}

size_t node_size(const Node *head) {
  const Node *node = head;
  size_t size = 0;
  while (node != NULL) {
    ++size;
    node = node->next;
  }
  return size;
}

size_t node_recur_size(const Node *head) {
  if (head == NULL) {
    return 0;
  }
  return node_recur_size(head->next) + 1;
}
