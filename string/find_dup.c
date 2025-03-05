#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void find_dup_using_hashtable(const char *str) {
  char *h = (char *)calloc(2 * ('z' - 'a' + 1), sizeof(char));
  if (h == NULL) {
    return;
  }
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (!isalpha(str[i])) {
      continue;
    }
    size_t index =
        islower(str[i]) ? str[i] - 'a' + ('z' - 'a' + 1) : str[i] - 'A';
    ++h[index];
    if (h[index] > 1) {
      printf("duplicate value: %c %d times\n", str[i], h[index]);
    }
  }
  free(h);
}

void find_dup_using_bits(const char *str) {
  long h = 0;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (!isalpha(str[i])) {
      continue;
    }
    long bit_shifts =
        islower(str[i]) ? str[i] - 'a' + ('z' - 'a' + 1) : str[i] - 'A';
    if (h & 1 << bit_shifts) {
      printf("duplicate value: %c\n", str[i]);
    }
    h |= 1 << bit_shifts;
  }
}

int main(int argc, char *argv[]) {
  const char *str = "this is testzZZ    WTFFwtffff";

  find_dup_using_hashtable(str);
  find_dup_using_bits(str);

  return 0;
}
