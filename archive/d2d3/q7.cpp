// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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
vector<vector<int>> g(55), capacity(55, vector<int> (55)), capacity1(55, vector<int> (55));

int bfs(int src, int sink, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});

  while (!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto v : g[u]) {
      if (par[v] == -1 && capacity[u][v] > 0) {
        int new_flow = min(flow, capacity[u][v]);
        par[v] = u;
        if (v == sink) return new_flow;
        qu.push({v, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow(int src, int sink) {
  vector<int> par(55, -1);

  int flow = 0, new_flow = 0;
  while (new_flow = bfs(src, sink, par)) {
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

void solve() {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    for (int j = 0; j <= n; j++) {
      capacity[i][j] = capacity[j][i] = 0;
      capacity1[i][j] = capacity1[j][i] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    capacity[u][v] = capacity[v][u] = w;
    capacity1[u][v] = capacity1[v][u] = w;
  }

  maxFlow(0, 1);

  vector<int> vis(n, 0);
  queue<int> qu;
  qu.push(0);
  vis[0] = 1;

  while(!qu.empty()) {
    int u = qu.front(); qu.pop();
    for (int v : g[u]) {
      if (!vis[v] && capacity[u][v] > 0) {
        vis[v] = 1;
        qu.push(v);
      }
    }
  }
  
  for (int u = 0; u < n; u++) {
    for (int v = u + 1; v < n; v++) {
      if (vis[u] != vis[v] && capacity1[u][v] > 0) {
        cout << u + 1 << " " << v + 1 << "\n";
      }
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 0;
  while (cin >> n >> m && n && m) {
    if (tt++) cout << "\n";
    solve();
  }

  return 0;
}
