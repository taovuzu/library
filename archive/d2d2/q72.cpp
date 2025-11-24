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

int n, m;
vector<vector<int>> g;
vector<int> vis, b;
vector<array<vector<int>, 2>> a;

bool dfs(int u, bool flag, vector<int>& c, vector<int>& d) {
  vis[u] = flag;
  if (flag) c.push_back(u);
  else d.push_back(u);

  bool is_bipartite = true;
  for (auto v : g[u]) {
    if (vis[v] == flag) {
      return false;
    }
    if (vis[v] == -1) {
      is_bipartite &= dfs(v, !flag, c, d);
    }
  }
  return is_bipartite;
}

bool rec(int idx, int suml, vector<int>& e) {
  if (suml > n) {
    return false;
  }

  if (idx == a.size()) {
    int k = n - suml;

    if (k >= 0 && k <= b.size()) {
      for (int i = 0; i < a.size(); i++) {
        for (int node : a[i][e[i]]) {
          cout << node << " ";
        }
      }

      for (int i = 0; i < k; i++) {
        cout << b[i] << " ";
      }
      cout << "\n";

      for (int i = 0; i < a.size(); i++) {
        for (int node : a[i][!e[i]]) {
          cout << node << " ";
        }
      }

      for (int i = k; i < b.size(); i++) {
        cout << b[i] << " ";
      }
      cout << "\n";

      return true;
    }
    return false;
  }

  e.push_back(0);

  if (rec(idx + 1, suml + a[idx][0].size(), e)) {
    return true;
  }
  e.pop_back();

  e.push_back(1);
  if (rec(idx + 1, suml + a[idx][1].size(), e)) {
    return true;
  }
  e.pop_back();

  return false;
}

void solve() {
  cin >> n >> m;

  int total_nodes = 2 * n;
  g.assign(total_nodes + 1, vector<int>());
  vis.assign(total_nodes + 1, -1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u); 
  }

  for (int i = 1; i <= total_nodes; i++) {
    if (vis[i] != -1) continue;

    vector<int> c, d;
    if (!dfs(i, 0, c, d)) {
      cout << "IMPOSSIBLE" << "\n";
      return;
    }

    if (c.empty() || d.empty()) {
      for (auto x : c) {
        b.push_back(x);
      }
      for (auto x : d) {
        b.push_back(x);
      }
    } else {
      a.push_back({d, c});
    }
  }

  vector<int> e;
  if (!rec(0, 0, e)) {
    cout << "IMPOSSIBLE" << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}