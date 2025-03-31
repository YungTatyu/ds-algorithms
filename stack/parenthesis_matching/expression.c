#include "stack.h"
#include <stddef.h>

int is_balanced(Stack *st, const char *exp) {
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
