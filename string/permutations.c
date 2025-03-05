#include <stddef.h>
#include <stdio.h>

void permutations(const char *s, size_t level) {
  static int pos[10] = {0};
  static char re[10] = {0};
  if (s[level] == '\0') {
    re[level] = '\0';
    printf("%s\n", re);
    return;
  }
  for (size_t i = 0; s[i] != '\0'; ++i) {
    if (pos[i] == 0) {
      pos[i] = 1;
      re[level] = s[i];
      permutations(s, level + 1);
      pos[i] = 0;
    }
  }
}

int main(int argc, char *argv[]) {

  permutations("abc", 0);
  permutations("abcd", 0);
  return 0;
}
