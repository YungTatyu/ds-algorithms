#include "expression.h"
#include "stack.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  const char *exp1 = "((a+b)*(c-d))";
  const char *exp2 = "((a+b)*(c-d)";
  printf("%d\n", is_balanced(stack_new(), exp1));
  printf("%d\n", is_balanced(stack_new(), exp2));

  return 0;
}
