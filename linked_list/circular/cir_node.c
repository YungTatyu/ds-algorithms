#include "cir_node.h"
#include <stddef.h>
#include <stdio.h>
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
  CirNode *tail = NULL;
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
      new_node->next = head;
    }
    tail = new_node;
  }
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

void cirnode_display(const CirNode *head) {
  const CirNode *node = head;
  do {
    printf("%d ", node->v);
    node = node->next;
  } while (node != head);
  printf("\n");
}

void cirnode_recur_display(const CirNode *head, const CirNode *node) {
  static int flag = 0;
  int is_first = flag;
  if (node != head || !is_first) {
    flag = 1;
    printf("%d ", node->v);
    cirnode_recur_display(head, node->next);
  }
  flag = 0;
  if (node == head && !is_first) {
    printf("\n");
  }
}

CirNode *cirnode_index(const CirNode *head, size_t index) {
  for (size_t i = 0; i < index; ++i) {
    head = head->next;
  }
  return (CirNode *)head;
}

CirNode *cirnode_last(const CirNode *head) {
  const CirNode *node = head;
  while (node != NULL && node->next != head) {
    node = node->next;
  }
  return (CirNode *)node;
}

void cirnode_insert(CirNode **head, CirNode *new_node, size_t index) {
  if (index > cirnode_size(*head)) {
    return;
  }
  if (index == 0) {
    CirNode *last = cirnode_last(*head);
    if (last) {
      new_node->next = last->next;
      last->next = new_node;
    }
    *head = new_node;
    return;
  }
  CirNode *node = cirnode_index(*head, index - 1);
  new_node->next = node->next;
  node->next = new_node;
}

size_t cirnode_size(const CirNode *head) {
  size_t size = 0;
  if (head == NULL) {
    return 0;
  }
  const CirNode *node = head;
  do {
    ++size;
    node = node->next;
  } while (node != head);
  return size;
}
