#include "stack.h"
#include <stddef.h>
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
