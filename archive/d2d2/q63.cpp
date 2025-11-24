#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

const double eps = 1e-9;
int dcomp(double x, double y) {
  return abs(x - y) <= eps ? 0 : (x < y ? 1 : -1);
}

int bfs(int src, int sink, vector<int>& par, const vector<vector<int>>& g,
        vector<vector<int>>& capacity) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});

  while (!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto nv : g[u]) {
      if (par[nv] == -1 && capacity[u][nv] > 0) {
        int new_flow = min(flow, capacity[u][nv]);
        par[nv] = u;
        if (nv == sink) return new_flow;
        qu.push({nv, new_flow});
      }
    }
  }
  return 0;
}

int maxFlow(int src, int sink, int n, int m, const vector<vector<int>>& g, vector<vector<int>>& capacity) {
  int flow = 0, new_flow = 0;
  vector<int> par(n + m + 2);

  while (new_flow = bfs(src, sink, par, g, capacity)) {
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[prev][curr] -= new_flow;
      capacity[curr][prev] += new_flow;
      curr = prev;
    }
  }
  return flow;
}

void solve(int n, int m, int s, int v) {
  vector<array<double, 2>> a(n + 1), b(m + 1);
  vector<vector<int>> g(n + m + 2);
  vector<vector<int>> capacity(n + m + 2, vector<int>(n + m + 2, 0));

  g[0].clear();
  g[n + m + 1].clear();

  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    g[0].push_back(i);
    g[i].push_back(0);
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i][0] >> b[i][1];
    g[i + n].push_back(n + m + 1);
    g[n + m + 1].push_back(i + n);
  }

  fill(capacity[0].begin(), capacity[0].begin() + n + 1, 1);
  for (int i = 1; i <= m; i++) {
    capacity[i + n][n + m + 1] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      double dis = (a[i][0] - b[j][0]) * (a[i][0] - b[j][0]) + (a[i][1] - b[j][1]) * (a[i][1] - b[j][1]);
      double fdis = s * v * s * v;
      if (dcomp(fdis, dis) <= 0) {
        g[i].push_back(j + n);
        g[j + n].push_back(i);
        capacity[i][j + n] = 1;
      }
    }
  }

  cout << n - maxFlow(0, n + m + 1, n, m, g, capacity) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, s, v;
  while (cin >> n >> m >> s >> v) {
    solve(n, m, s, v);
  }

  return 0;
}
