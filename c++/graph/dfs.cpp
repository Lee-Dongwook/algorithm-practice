#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> *adj, int u, int v) {
  (*adj)[u - 1].push_back(v - 1);
  (*adj)[v-1].push_back(u-1);
}

void explore(const vector<vector<int>> &adj, int v, vector<bool> *isVisited) {
  cout << v + 1 << " ";
  (*isVisited)[v] = true;

  for (auto x : adj[v]) {
    if (!(*isVisited)[x]) {
      explore(adj, x, isVisited);
    }
  }
}

void dfs(const vector<vector<int>> &adj, int start) {
  int vertices = adj.size();

  vector<bool> isVisited(vertices, false);
  explore(adj, start, &isVisited);
}

int main() {
  int vertices = 0;
  int edges = 0;

  cout << "Enter the Vertices : ";
  cin >> vertices;
  cout << "Enter the Edges : ";
  cin >> edges;

  vector<vector<int>> adj(vertices, vector<int>());

  cout << "Enter the vertices which have edges between them : " << endl;

  while (edges--) {
    int u = 0;
    int v = 0;
    cin >> u >> v;
    addEdge(&adj, u, v);
  }

  dfs(adj, 2);

  cout << endl;

  return 0;
}
