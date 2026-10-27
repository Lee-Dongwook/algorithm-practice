#include <cassert>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

#define INF 987654321
using namespace std;

void addEdge(vector<vector<pair<int, int>>> * adj, int u, int v, int w) {
  (*adj)[u-1].push_back(make_pair(v-1, w));
}

int dijkstra(vector<vector<pair<int, int>>> * adj, int s, int t) {
  int n = adj->size();

  vector<int> dist(n, INF);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push(make_pair(0, s));

  dist[s] = 0;

  while (!pq.empty()) {
    int currentNode = pq.top().second;
    int currentDist = pq.top().first;

    pq.pop();

    for (pair<int, int> edge : (*adj)[currentNode]) {
      if (currentDist + edge.second < dist[edge.first]) {
        dist[edge.first] = currentDist + edge.second;
        pq.push(make_pair(dist[edge.first], edge.first));
      }
    }
  }

  if (dist[t] != INF) {
    return dist[t];
  }

  return -1;
}

int main() {
  int vertices = int(), edges = int();
  cout << "Enter the number of vertices : ";
  cin >> vertices;
  cout << "Enter the number of edges : ";
  cin >> edges;

  vector<vector<pair<int, int>>> adj(vertices, vector<pair<int, int>>());

  int u = int(), v = int(), w = int();

  while (edges--) {
    cin >> u >> v >> w;
    addEdge(&adj, u, v, w);
  }

  int s = int(), t = int();
  cin >> s >> t;

  int dist = dijkstra(&adj, s-1, t-1);
  if (dist == -1) {
    cout << "Target not reachable" << endl;
  } else {
    cout << "Shortest path: " << dist << endl;
  }
  return 0;
}
