#include <iostream>
#include <queue>

void bfs(int graph[][7], int start, int n) {
  std::queue<int> queue;
  bool visited[7] = {false};

  /*print visited node*/
  std::cout << start << " ";
  queue.push(start);
  visited[start] = true;

  while (!queue.empty()) {
    int fi = queue.front();
    queue.pop();
    for (int si = 1; si < n; ++si) {
      if (graph[fi][si] == 1 && visited[si] == false) {
        std::cout << si << " ";
        visited[si] = true;
        queue.push(si);
      }
    }
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {

  /*ignore index 0 on both metrix*/
  /*so total number of nodes are 6*/
  int graph[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};

  bfs(graph, 1, 7);
  bfs(graph, 4, 7);
  bfs(graph, 5, 7);

  return 0;
}
