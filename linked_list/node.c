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
  while (head != NULL) {
    printf("%d ", head->v);
    head = head->next;
  }
  printf("\n");
}

void node_recur_display(const Node *head) {
  if (head == NULL) {
    return;
  }
  printf("%d ", head->v);
  node_recur_display(head->next);
}

size_t node_size(const Node *head) {
  size_t size = 0;
  while (head != NULL) {
    ++size;
    head = head->next;
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
  int sum = 0;
  while (head != NULL) {
    sum += head->v;
    head = head->next;
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
  while (head != NULL) {
    if (head->v > max) {
      max = head->v;
      head = head->next;
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
  while (head != NULL) {
    if (head->v == key) {
      return (Node *)head;
    }
    head = head->next;
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

void node_insert(Node **head, size_t index, Node *new_node) {
  if (new_node == NULL || index > node_size(*head)) {
    return;
  }
  Node *node = *head;
  if (index == 0) {
    new_node->next = node;
    *head = new_node;
    return;
  }
  node = node_index(node, index - 1);
  new_node->next = node->next;
  node->next = new_node;
}

void node_sorted_insert(Node **head, Node *new_node) {
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  Node *ahead = *head;
  Node *behind = NULL;
  while (ahead != NULL) {
    if (new_node->v < ahead->v) {
      break;
    }
    behind = ahead;
    ahead = ahead->next;
  }
  if (ahead == *head) {
    new_node->next = *head;
    *head = new_node;
    return;
  }
  new_node->next = ahead;
  behind->next = new_node;
}

Node *node_index(const Node *head, size_t index) {
  for (size_t i = 0; i < index; ++i) {
    head = head->next;
  }
  return (Node *)head;
}

int node_delete_from_list(Node **head, size_t index) {
  if (index >= node_size(*head)) {
    return 0;
  }
  if (index == 0) {
    Node *tmp = *head;
    int v = tmp->v;
    *head = tmp->next;
    node_delete(tmp);
    return v;
  }
  Node *node = node_index(*head, index - 1);
  Node *delete = node->next;
  node->next = delete->next;
  int v = delete->v;
  node_delete(delete);
  return v;
}
