#include <limits.h>
#define LENGTH 8
#define I INT_MAX // INF as I

void PrimsMST(int cost[][LENGTH], int n) {
  int min = INT_MAX;
  int min_fi, min_si;
  int fi, si;
  int t[2][LENGTH - 2] = {0}; // solution tree
  int near[LENGTH] = {I};

  /*find the smallest wight*/
  for (fi = 1; fi < LENGTH; ++fi) {
    for (si = fi; si < LENGTH; ++si) {
      if (cost[fi][si] < min) {
        min_fi = fi;
        min_si = si;
        min = cost[fi][si];
      }
    }
  }
  t[0][0] = fi;
  t[1][0] = si;
}

int main() {

  /*ignore index 0*/
  int cost[LENGTH][LENGTH]{
      {I, I, I, I, I, I, I, I},    {I, I, 25, I, I, I, 5, I},
      {I, 25, I, 12, I, I, I, 10}, {I, I, 12, I, 8, I, I, I},
      {I, I, I, 8, I, 16, I, 14},  {I, I, I, I, 16, I, 20, 18},
      {I, 5, I, I, I, 20, I, I},   {I, I, 10, I, 14, 18, I, I},
  };

  int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;

  PrimsMST(cost, n);

  return 0;
}
