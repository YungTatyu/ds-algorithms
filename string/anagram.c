#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

/**
 * are these strings consist of same letters of elements aks anagram?
 * check only alpha and num elements
 */
int check_anagram(const char *s1, const char *s2) {
  long s1h = 0;
  long s2h = 0;
  for (size_t i = 0; s1[i] != '\0'; ++i) {
    if (!isalpha(s1[i])) {
      continue;
    }
    long bit_shifts =
        islower(s1[i]) ? s1[i] - 'a' + ('z' - 'a' + 1) : s1[i] - 'A';
    s1h |= 1 << bit_shifts;
  }
  for (size_t i = 0; s2[i] != '\0'; ++i) {
    if (!isalpha(s2[i])) {
      continue;
    }
    long bit_shifts =
        islower(s2[i]) ? s2[i] - 'a' + ('z' - 'a' + 1) : s2[i] - 'A';
    s2h |= 1 << bit_shifts;
  }
  return s1h == s2h;
}

int main(int argc, char *argv[]) {

  printf("%d\n", check_anagram("decimal", "medical"));
  printf("%d\n", check_anagram("evil", "live"));
  printf("%d\n", check_anagram("earth", "heart"));
  printf("%d\n", check_anagram("The eyes", "They see"));
  printf("%d\n", check_anagram("testes", "medical"));
  printf("%d\n", check_anagram("taste", "tests"));
  return 0;
}
