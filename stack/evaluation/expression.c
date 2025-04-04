#include "stack.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int is_balanced_min(CStack *st, const char *exp) {
  for (size_t i = 0; exp[i] != '\0'; ++i) {
    if (exp[i] == '(') {
      cstack_push(st, '(');
    } else if (exp[i] == ')') {
      if (cstack_empty(st)) {
        return 0;
      }
      cstack_pop(st);
    }
  }
  return cstack_empty(st);
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

int is_balanced(CStack *st, const char *exp) {
  for (size_t i = 0; exp[i] != '\0'; ++i) {
    if (strchr("([{", exp[i]) != NULL) {
      cstack_push(st, exp[i]);
    } else if (strchr(")]}", exp[i]) != NULL) {
      if (cstack_empty(st)) {
        return 0;
      }
      char open = cstack_pop(st);
      if (!is_matching_bracket(open, exp[i])) {
        return 0;
      }
    }
  }
  return cstack_empty(st);
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
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
         ch == '(' || ch == ')';
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
  CStack *st = cstack_new();
  if (st == NULL) {
    free(postfix);
    return NULL;
  }
  while (infix[in_i] != '\0') {
    char ch = infix[in_i];
    if (is_operator(ch)) {
      if (cstack_empty(st) || precedence(ch) > precedence(cstack_top(st))) {
        cstack_push(st, ch);
      } else {
        while (!cstack_empty(st) &&
               precedence(ch) <= precedence(cstack_top(st))) {
          postfix[post_i] = cstack_pop(st);
          ++post_i;
        }
        cstack_push(st, ch);
      }
    } else {
      postfix[post_i] = ch;
      ++post_i;
    }
    ++in_i;
  }
  while (!cstack_empty(st)) {
    postfix[post_i] = cstack_pop(st);
    ++post_i;
  }
  cstack_delete(st);
  return postfix;
}

/**
 *
 * () not handled
 */
char *convert_v2(const char *infix) {
  char *postfix = calloc(strlen(infix) + 1, sizeof(char));
  if (postfix == NULL) {
    return NULL;
  }
  size_t in_i = 0;
  size_t post_i = 0;
  CStack *st = cstack_new();
  if (st == NULL) {
    free(postfix);
    return NULL;
  }
  while (infix[in_i] != '\0') {
    char ch = infix[in_i];
    if (is_operator(ch)) {
      if (cstack_empty(st) || precedence(ch) > precedence(cstack_top(st))) {
        cstack_push(st, ch);
        ++in_i;
      } else {
        postfix[post_i] = cstack_pop(st);
        ++post_i;
      }
    } else {
      postfix[post_i] = ch;
      ++post_i;
      ++in_i;
    }
  }
  while (!cstack_empty(st)) {
    postfix[post_i] = cstack_pop(st);
    ++post_i;
  }
  cstack_delete(st);
  return postfix;
}

int out_stack_precedence(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 3;
  case '^':
    return 6;
  case '(':
    return 7;
  case ')':
    return 0;
  default:
    return -1;
  }
}

int in_stack_precedence(char op) {
  switch (op) {
  case '+':
  case '-':
    return 2;
  case '*':
  case '/': // these above are left to right associative
    return 4;
  case '^': // ^ is right to left associative
    return 5;
  case '(':
    return 0;
  default:
    // ) does not get pushed to stack
    return -1;
  }
}

/**
 * higher precedence get pushed to stack
 */
char *convert(const char *infix) {
  char *postfix = calloc(strlen(infix) + 1, sizeof(char));
  if (postfix == NULL) {
    return NULL;
  }
  size_t in_i = 0;
  size_t post_i = 0;
  CStack *st = cstack_new();
  if (st == NULL) {
    free(postfix);
    return NULL;
  }
  while (infix[in_i] != '\0') {
    char ch = infix[in_i];
    if (is_operator(ch)) {
      if (cstack_empty(st) ||
          out_stack_precedence(ch) > in_stack_precedence(cstack_top(st))) {
        cstack_push(st, ch);
        ++in_i;
      } else if (out_stack_precedence(ch) ==
                 in_stack_precedence(cstack_top(st))) {
        // only ( and ) are equals 0 ( == )
        cstack_pop(st);
        ++in_i;
      } else {
        postfix[post_i] = cstack_pop(st);
        ++post_i;
      }
    } else {
      postfix[post_i] = ch;
      ++post_i;
      ++in_i;
    }
  }
  while (!cstack_empty(st)) {
    postfix[post_i] = cstack_pop(st);
    ++post_i;
  }
  cstack_delete(st);
  return postfix;
}

int power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  }
  if (exponent % 2 == 0) {
    return power(base * base, exponent / 2);
  } else {
    return base * power(base * base, (exponent - 1) / 2);
  }
}

int eval(const char *postfix) {
  Stack *st = stack_new();
  if (st == NULL) {
    return -1;
  }
  for (size_t i = 0; postfix[i] != '\0'; ++i) {
    if (is_operator(postfix[i])) {
      if (stack_size(st) < 2) {
        stack_delete(st);
        return -1;
      }
      int v2 = stack_pop(st);
      int v1 = stack_pop(st);
      int re = 0;
      switch (postfix[i]) {
      case '+':
        re = v1 + v2;
        break;
      case '-':
        re = v1 - v2;
        break;
      case '*':
        re = v1 * v2;
        break;
      case '/':
        re = v1 / v2;
        break;
      case '^':
        re = power(v1, v2);
        break;
      default:
        break;
      }
      stack_push(st, re);
    } else {
      stack_push(st, (int)(postfix[i] - '0'));
    }
  }
  int re = stack_pop(st);
  stack_delete(st);
  return re;
}
