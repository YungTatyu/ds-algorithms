#include <iostream>
#include <limits.h>
#define LENGTH 8
#define I INT_MAX // INF as I

void PrimsMST(int cost[][LENGTH], int n) {
  int min = INT_MAX;
  int min_fi, min_si;
  int fi, si;
  int t[2][LENGTH - 2] = {}; // solution tree
  int near[LENGTH];

  /*find the smallest wight*/
  for (fi = 1; fi <= n; ++fi) {
    for (si = fi; si <= n; ++si) {
      if (cost[fi][si] < min) {
        min_fi = fi;
        min_si = si;
        min = cost[fi][si];
      }
    }
  }
  /*pick two vertex*/
  t[0][0] = min_fi;
  t[1][0] = min_si;
  near[min_fi] = near[min_si] = 0; // 0 as already selected vertex

  /*init near array*/
  /*find the near vertex connecting to the two chosen vertex*/
  /*index implies vertex*/
  for (int i = 1; i <= n; ++i) {
    if (near[i] == 0) {
      continue;
    }
    if (cost[i][min_fi] < cost[i][min_si]) {
      near[i] = min_fi;
    } else {
      near[i] = min_si;
    }
  }

  for (int ti = 1; ti < n - 1; ++ti) {
    min = INT_MAX;
    int k; // min vertex
    for (int mi = 1; mi <= n; ++mi) {
      if (near[mi] != 0 && cost[mi][near[mi]] < min) {
        k = mi;
        min = cost[mi][near[mi]];
      }
    }
    std::cout << "ti:" << ti << " k:" << k << "\n";
    t[0][ti] = k;
    t[1][ti] = near[k];
    near[k] = 0;

    /*update near vertex*/
    for (int i = 1; i <= n; ++i) {
      if (near[i] != 0 && cost[i][k] < cost[i][near[i]]) {
        near[i] = k;
      }
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    std::cout << "(" << t[0][i] << "," << t[1][i] << ")\n";
  }
}

int main() {

  /*ignore index 0*/
  int cost[LENGTH][LENGTH]{
      {I, I, I, I, I, I, I, I},    {I, I, 25, I, I, I, 5, I},
      {I, 25, I, 12, I, I, I, 10}, {I, I, 12, I, 8, I, I, I},
      {I, I, I, 8, I, 16, I, 14},  {I, I, I, I, 16, I, 20, 18},
      {I, 5, I, I, I, 20, I, I},   {I, I, 10, I, 14, 18, I, I},
  };

  int n = LENGTH - 1;

  PrimsMST(cost, n);

  return 0;
}
