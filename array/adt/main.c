#include "array.h"

int main(int argc, char *argv[]) {
  Array *arr = array_new(10);
  array_display(arr);
  return 0;
}
