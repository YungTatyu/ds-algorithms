#pragma once

#include <stddef.h>

struct Node {
  int v;
  struct Node *next;
};

typedef struct Node Node;

Node *node_new(int v);

Node *node_list_new(const int *arr, size_t size);

void node_delete(Node *node);

void node_list_delete(Node *head);

void node_display(const Node *head);

void node_recur_display(const Node *head);

size_t node_size(const Node *head);

size_t node_recur_size(const Node *head);

int node_sum(const Node *head);

int node_recur_sum(const Node *head);

int node_max(const Node *head);

int node_recur_max(const Node *head);

Node *node_search(const Node *head, int key);

Node *node_recur_search(const Node *head, int key);

Node *node_search_with_move_front(Node **head, int key);

Node *node_index(const Node *head, size_t index);

void node_insert(Node **head, size_t index, Node *new_node);

void node_sorted_insert(Node **head, Node *new_node);

int node_delete_from_list(Node **head, size_t index);

int node_is_sorted(const Node *head);

void node_remove_duplicate(Node *head);

void node_reverse_with_array(Node *head);

void node_reverse(Node **head);

void node_recur_reverse(Node **head, Node *ahead, Node *behind);

Node *node_last(const Node *head);

void node_concat(Node *head1, Node *head2);

Node *node_merge(Node *head1, Node *head2);

int node_is_loop(const Node *head);
