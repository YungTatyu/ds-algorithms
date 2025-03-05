#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_anagram_usgin_hashtable(const char *s1, const char *s2) {
  // size of ascii
  int size_ascii = 128;
  int *h = (int *)calloc(size_ascii, sizeof(int));
  for (size_t i = 0; s1[i] != '\0'; ++i) {
    ++h[s1[i]];
  }
  for (size_t i = 0; s2[i] != '\0'; ++i) {
    --h[s2[i]];
  }
  int re = memcmp(h, (int[128]){0}, sizeof(int) * size_ascii) == 0;
  free(h);
  return re;
}
/**
 * are these strings consist of same letters of elements aka anagram?
 * check only alpha elements
 * WARN: only use this when strings have no duplicates
 */
int check_anagram_usgin_bits(const char *s1, const char *s2) {
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

  printf("%d\n", check_anagram_usgin_bits("decimal", "medical"));
  printf("%d\n", check_anagram_usgin_bits("evil", "live"));
  printf("%d\n", check_anagram_usgin_bits("earth", "heart"));
  printf("%d\n", check_anagram_usgin_bits("The eyes", "They see"));
  printf("%d\n", check_anagram_usgin_bits("testes", "medical"));
  printf("%d\n", check_anagram_usgin_bits("taste", "tests"));
  printf("%d\n", check_anagram_usgin_bits("verbose", "observe"));
  printf("%d\n", check_anagram_usgin_bits("verboseo", "observes")); // error

  printf("%d\n", check_anagram_usgin_hashtable("decimal", "medical"));
  printf("%d\n", check_anagram_usgin_hashtable("evil", "live"));
  printf("%d\n", check_anagram_usgin_hashtable("earth", "heart"));
  printf("%d\n", check_anagram_usgin_hashtable("The eyes", "They see"));
  printf("%d\n", check_anagram_usgin_hashtable("testes", "medical"));
  printf("%d\n", check_anagram_usgin_hashtable("taste", "tests"));
  printf("%d\n", check_anagram_usgin_hashtable("ddt", "tdd"));
  printf("%d\n", check_anagram_usgin_hashtable("ddtt", "tdd"));
  printf("%d\n", check_anagram_usgin_hashtable("verbose", "observe"));
  printf("%d\n", check_anagram_usgin_hashtable("verboseo", "observes"));
  return 0;
}
