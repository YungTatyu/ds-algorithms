#include "node.h"
#include <limits.h>
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

int node_sum(const Node *head) {
  const Node *node = head;
  int sum = 0;
  while (node != NULL) {
    sum += node->v;
    node = node->next;
  }
  return sum;
}

int node_recur_sum(const Node *head) {
  if (head == NULL) {
    return 0;
  }
  return node_recur_sum(head->next) + head->v;
}

int node_max(const Node *head) {
  int max = INT_MIN;
  const Node *node = head;
  while (node != NULL) {
    if (node->v > max) {
      max = node->v;
      node = node->next;
    }
  }
  return max;
}

int node_recur_max(const Node *head) {
  if (head == NULL) {
    return INT_MIN;
  }
  int max = node_recur_max(head->next);
  return head->v > max ? head->v : max;
}

Node *node_search(const Node *head, int key) {
  const Node *node = head;
  while (node != NULL) {
    if (node->v == key) {
      return (Node *)node;
    }
    node = node->next;
  }
  return NULL;
}

Node *node_recur_search(const Node *head, int key) {
  if (head == NULL) {
    return NULL;
  }
  if (head->v == key) {
    return (void *)head;
  }
  return node_recur_search(head->next, key);
}

Node *node_search_with_move_front(Node **head, int key) {
  Node *node = *head;
  Node *behind_node = NULL;
  while (node != NULL) {
    if (node->v == key) {
      if (behind_node != NULL) {
        behind_node->next = node->next;
      } else if (*head == node) {
        return node;
      }
      node->next = *head;
      *head = node;
      return node;
    }
    behind_node = node;
    node = node->next;
  }
  return NULL;
}
