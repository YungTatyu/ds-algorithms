#include "stack.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int is_balanced_min(Stack *st, const char *exp) {
  for (size_t i = 0; exp[i] != '\0'; ++i) {
    if (exp[i] == '(') {
      stack_push(st, '(');
    } else if (exp[i] == ')') {
      if (stack_empty(st)) {
        return 0;
      }
      stack_pop(st);
    }
  }
  return stack_empty(st);
}

int is_matching_bracket(char open, char close) {
  switch (open) {
  case '(':
    return close == ')';
  case '[':
    return close == ']';
  case '{':
    return close == '}';
  default:
    return 0;
  }
}

int is_balanced(Stack *st, const char *exp) {
  for (size_t i = 0; exp[i] != '\0'; ++i) {
    if (strchr("([{", exp[i]) != NULL) {
      stack_push(st, exp[i]);
    } else if (strchr(")]}", exp[i]) != NULL) {
      if (stack_empty(st)) {
        return 0;
      }
      char open = stack_pop(st);
      if (!is_matching_bracket(open, exp[i])) {
        return 0;
      }
    }
  }
  return stack_empty(st);
}

int precedence(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

int is_operator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

/**
 * before refactor to convert
 */
char *convert_v1(const char *infix) {
  char *postfix = calloc(strlen(infix) + 1, sizeof(char));
  if (postfix == NULL) {
    return NULL;
  }
  size_t in_i = 0;
  size_t post_i = 0;
  Stack *st = stack_new();
  if (st == NULL) {
    free(postfix);
    return NULL;
  }
  while (infix[in_i] != '\0') {
    char ch = infix[in_i];
    if (is_operator(ch)) {
      if (stack_empty(st) || precedence(ch) > precedence(stack_top(st))) {
        stack_push(st, ch);
      } else {
        while (!stack_empty(st) &&
               precedence(ch) <= precedence(stack_top(st))) {
          postfix[post_i] = stack_pop(st);
          ++post_i;
        }
        stack_push(st, ch);
      }
    } else {
      postfix[post_i] = ch;
      ++post_i;
    }
    ++in_i;
  }
  while (!stack_empty(st)) {
    postfix[post_i] = stack_pop(st);
    ++post_i;
  }
  stack_delete(st);
  return postfix;
}

char *convert(const char *infix) {
  char *postfix = calloc(strlen(infix) + 1, sizeof(char));
  if (postfix == NULL) {
    return NULL;
  }
  size_t in_i = 0;
  size_t post_i = 0;
  Stack *st = stack_new();
  if (st == NULL) {
    free(postfix);
    return NULL;
  }
  while (infix[in_i] != '\0') {
    char ch = infix[in_i];
    if (is_operator(ch)) {
      if (stack_empty(st) || precedence(ch) > precedence(stack_top(st))) {
        stack_push(st, ch);
        ++in_i;
      } else {
        postfix[post_i] = stack_pop(st);
        ++post_i;
      }
    } else {
      postfix[post_i] = ch;
      ++post_i;
      ++in_i;
    }
  }
  while (!stack_empty(st)) {
    postfix[post_i] = stack_pop(st);
    ++post_i;
  }
  stack_delete(st);
  return postfix;
}
