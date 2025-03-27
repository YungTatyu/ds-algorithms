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

void doubnode_insert(DoubNode **head, DoubNode *new_node, size_t index) {
  if (index > doubnode_size(*head)) {
    return;
  }
  if (index == 0) {
    if (*head != NULL) {
      new_node->next = (*head);
    }
    *head = new_node;
    return;
  }
  DoubNode *prev = doubnode_index(*head, index - 1);
  DoubNode *next = prev->next;
  new_node->next = next;
  new_node->prev = prev;
  prev->next = new_node;
  if (next != NULL) {
    next->prev = new_node;
  }
}

DoubNode *doubnode_index(const DoubNode *head, size_t index) {
  for (size_t i = 0; i < index; ++i) {
    head = head->next;
  }
  return (DoubNode *)head;
}

DoubNode *doubnode_last(const DoubNode *head) {
  while (head != NULL && head->next != NULL) {
    head = head->next;
  }
  return (DoubNode *)head;
}

int doubnode_delete_from_list(DoubNode **head, size_t index) {
  if (index >= doubnode_size(*head)) {
    return 0;
  }
  if (index == 0) {
    DoubNode *delete = *head;
    *head = delete->next;
    if (*head != NULL) {
      (*head)->prev = NULL;
    }
    int v = delete->v;
    doubnode_delete(delete);
    return v;
  }
  DoubNode *delete = doubnode_index(*head, index);
  DoubNode *prev = delete->prev;
  DoubNode *next = delete->next;
  prev->next = next;
  if (next != NULL) {
    next->prev = prev;
  }
  int v = delete->v;
  doubnode_delete(delete);
  return v;
}
