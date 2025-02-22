#define NUM_EDGES 9
#define NUM_VERTICES (NUM_EDGES - 1)
#define I INT_MIN
#include <limits.h>

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
    set[vertex_fi] = set[vertex_fi] + set[vertex_si];
    set[vertex_si] = vertex_fi;
  } else {
    set[vertex_si] = set[vertex_si] + set[vertex_fi];
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
    v = set[index];
  }
  return v;
}

void Krusklas(int edges[][], int num_vertices, int num_edges) {
  // index 0 is not used
  int set[NUM_VERTICES] = {-1};
  bool included[NUM_EDGES] = {false};

  int i = 0;
  while (i < num_vertices - 1) {
    int min = I;
    int min_fv, min_sv; // stroe min vertex pair
    int min_index;
    for (int ei = 0; ei < num_edges; ++ei) {
      if (edges[2][ei] < min) {
        min = edges[2][ei];
        min_fv = edges[0][ei];
        min_fv = edges[1][ei];
        min_index = ei;
      }
    }

    find_parent(min_fv);
  }
}

int main(int argc, char *argv[]) {
  // [0] vertex
  // [1] vertex
  // [2] cost of the edge
  int edges[3][NUM_EDGES] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                             {2, 6, 3, 7, 4, 5, 7, 6, 7},
                             {25, 5, 12, 10, 8, 16, 14, 20, 18}};

  return 0;
}
