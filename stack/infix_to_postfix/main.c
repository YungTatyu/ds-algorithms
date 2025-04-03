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
  printf("Test 1: %s       // Expected: abc*+\n", convert("a+b*c"));
  printf("Test 2: %s   // Expected: abc*+de/-\n", convert("a+b*c-d/e"));
  printf("Test 3: %s       // Expected: ab-c+\n", convert("a-b+c"));
  printf("Test 4: %s     // Expected: abc*/d-\n", convert("a*b/c-d"));
  printf("Test 5: %s   // Expected: ab*c*d/e+\n", convert("a*b*c/d+e"));
  printf("Test 6: %s // Expected: abc*+de^f/-\n", convert("a+b*c-d/e^f"));
  printf("Test 7: %s // Expected: abc*d/-ef*+\n", convert("a-b*c/d+e*f"));
  printf("Test 8: %s // Expected: ab+cd*ef^/-\n", convert("a+b-c*d/e^f"));
  printf("Test 9: %s // Expected: ab+c*def^^-\n", convert("((a+b)*c-d^e^f)"));

  return 0;
}
