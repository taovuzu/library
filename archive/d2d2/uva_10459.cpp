#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> g[5005];

pair<int, vector<int>> bfs(int start) {
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;

  int farthestNode = start;
  int maxDist = 0;

  while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int neighbor : g[node]) {
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[node] + 1;
        if (dist[neighbor] > maxDist) {
          maxDist = dist[neighbor];
          farthestNode = neighbor;
        }
        q.push(neighbor);
      }
    }
  }

  return {farthestNode, dist};
}

vector<int> getPath(int start, int end) {
  vector<int> parent(n, -1);
  queue<int> q;
  q.push(start);
  parent[start] = -2;

  while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int neighbor : g[node]) {
      if (parent[neighbor] == -1) {
        parent[neighbor] = node;
        q.push(neighbor);
      }
    }
  }

  vector<int> path;
  for (int cur = end; cur != -2; cur = parent[cur]) {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());
  return path;
}

void solve() {
  for (int i = 0; i < n; i++) {
    g[i].clear();
    int m, x;
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> x;
      g[i].push_back(x - 1);
    }
  }

  auto [u, _] = bfs(0);
  auto [v, distFromU] = bfs(u);
  auto [__, distFromV] = bfs(v);
  vector<int> path = getPath(u, v);

  cout << "Best Roots  :";
  if (path.size() % 2 == 1) {
    cout << " " << path[path.size() / 2] + 1 << "\n";
  } else {
    cout << " " << min(path[path.size() / 2 - 1] + 1, path[path.size() / 2] + 1) << " " << max(path[path.size() / 2 - 1] + 1, path[path.size() / 2] + 1) << "\n";
  }

  int maxHeight = 0;
  vector<int> worstRoots;
  for (int i = 0; i < n; i++) {
    int height = max(distFromU[i], distFromV[i]);
    if (height > maxHeight) {
      maxHeight = height;
      worstRoots.clear();
      worstRoots.push_back(i + 1);
    } else if (height == maxHeight) {
      worstRoots.push_back(i + 1);
    }
  }

  cout << "Worst Roots :";
  for (int node : worstRoots) {
    cout << " " << node;
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n) {
    solve();  
  }

  return 0;
}
