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

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void permutations_modifying_s(char *s, size_t low, size_t high) {
  if (low == high) {
    printf("%s\n", s);
    return;
  }
  for (size_t i = low; s[i] != '\0'; ++i) {
    swap(&s[i], &s[low]);
    permutations_modifying_s(s, low + 1, high);
    swap(&s[i], &s[low]);
  }
}

int main(int argc, char *argv[]) {

  permutations("abc", 0);
  char s[] = "xyz";
  permutations_modifying_s(s, 0, 2);
  return 0;
}
