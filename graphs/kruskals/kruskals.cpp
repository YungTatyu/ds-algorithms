#include <cstdio>
#include <iostream>
#include <limits.h>

#define NUM_EDGES 9
#define NUM_VERTICES (NUM_EDGES - 1)
#define I INT_MAX

/**
 * @brief unite two vertixes to one.
 * whichever vertex has more children is a new parent.
 *
 * value negative means how many children the vertex has.
 * positive value implies the parent vertex.
 */
void Union(int vertex_fi, int vertex_si, int set[]) {
  // whichever vertex has more children is a new parent
  if (set[vertex_fi] < set[vertex_si]) {
    set[vertex_fi] += set[vertex_si];
    set[vertex_si] = vertex_fi;
  } else {
    set[vertex_si] += set[vertex_fi];
    set[vertex_fi] = vertex_si;
  }
}

/**
 * @brief find the parent of the vertex
 * negative value means how many children it has and it is a parent.
 */
int FindParent(int set[], int index) {
  int v = index;
  while (set[v] > 0) {
    v = set[v];
  }
  return v;
}

void KruskalsMCST(int edges[][NUM_EDGES], int num_vertices, int num_edges) {
  // index 0 is not used
  int set[NUM_VERTICES] = {-1, -1, -1, -1,
                           -1, -1, -1, -1}; // Array for finding cycle
  bool included[NUM_EDGES] = {false};
  int t[2][NUM_VERTICES - 1] = {-1};

  int i = 0;
  while (i < NUM_VERTICES - 1) {
    int min = I;
    int min_fv, min_sv; // stroe min vertex pair
    int min_index = 0;
    for (int ei = 0; ei < num_edges; ++ei) {
      if (included[ei] == false && edges[2][ei] < min) {
        min = edges[2][ei];
        min_fv = edges[0][ei];
        min_sv = edges[1][ei];
        min_index = ei;
      }
    }

    if (FindParent(set, min_fv) != FindParent(set, min_sv)) {
      // put the vertixes to the result
      t[0][i] = min_fv;
      t[1][i] = min_sv;
      Union(FindParent(set, min_fv), FindParent(set, min_sv), set);
      ++i;
    }
    included[min_index] = true;
  }

  for (int i = 0; i < num_vertices - 1; ++i) {
    std::cout << "(" << t[0][i] << "," << t[1][i] << ")\n";
  }
}

int main(int argc, char *argv[]) {
  // [0] vertex
  // [1] vertex
  // [2] cost of the edge
  int edges[3][NUM_EDGES] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                             {2, 6, 3, 7, 4, 5, 7, 6, 7},
                             {25, 5, 12, 10, 8, 16, 14, 20, 18}};
  KruskalsMCST(edges, NUM_VERTICES, NUM_EDGES);

  return 0;
}
