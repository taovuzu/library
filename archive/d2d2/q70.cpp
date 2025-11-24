// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
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

// 08:52

int n, m;
vector<vector<int>> g(250), capacity(250, vector<int> (250));

int bfs(int src, int sink, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});

  while (!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto v : g[u]) {
      if (par[v] == -1 && capacity[u][v]) {
        int new_flow = min(flow, capacity[u][v]);
        par[v] = u;
        if (v == sink) return new_flow;
        qu.push({v, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow (int src, int sink) {
  vector<int> par(2 * n + 5);
  int flow = 0, new_flow = 0;
  
  while (new_flow = bfs(src, sink, par)) {
    flow += new_flow;
    int curr =sink;
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
  cin >> n >> m;

  for (int i = 0; i < 2 * n + 5; i++) {
    g[i].clear();
    for (int j = 0; j < 2 * n + 5; j++) {
      capacity[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[0].push_back(u);
    g[u].push_back(0);
    g[n + v].push_back(2 * n + 1);
    g[2 * n + 1].push_back(n + v);
    g[u].push_back(n + v);
    g[n + v].push_back(u);
    capacity[0][u] = 1;
    capacity[n + v][2 * n + 1] = 1;
    capacity[u][n + v] = 1;
  }

  int ans = n - maxFlow(0, 2 * n + 1);
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
