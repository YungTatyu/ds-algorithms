#include "expression.h"
#include "stack.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  const char *exp1 = "((a+b)*(c-d))";
  const char *exp2 = "((a+b)*(c-d)";
  const char *exp3 = "([a+b]*{c-d})";
  const char *exp4 = "([a+b]*{c-d})}";
  printf("%d\n", is_balanced(stack_new(), exp1));
  printf("%d\n", is_balanced(stack_new(), exp2));
  printf("%d\n", is_balanced(stack_new(), exp3));
  printf("%d\n", is_balanced(stack_new(), exp4));
  printf("Test 1: %s\n", convert("a+b*c"));       // Expected: "abc*+"
  printf("Test 2: %s\n", convert("a+b*c-d/e"));   // Expected: "abc*+de/-"
  printf("Test 3: %s\n", convert("(a+b)*c"));     // Expected: "ab+c*"
  printf("Test 4: %s\n", convert("a+b*(c^d-e)")); // Expected: "abcd^e-*+"

  return 0;
}
