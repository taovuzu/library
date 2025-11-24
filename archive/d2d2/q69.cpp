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

int n, m, k;
vector<vector<int>> g(210), capacity(210, vector<int> (210));

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

int maxFlow(int src, int sink) {
  vector<int> par(n + m + 5);
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
  for (int i = 0; i < (n + m + 5); i++) {
    g[i].clear();
    for (int j = 0; j < (n + m + 5); j++) {
      capacity[i][j] = 0;
    }
  }

  for (int i = 0; i < k; i++) {
    int j, x, y;
    cin >> j >> x >> y;
    if (x == 0 || y == 0) continue;
    g[0].push_back(2 + x);
    g[2 + x].push_back(0);
    capacity[0][2 + x] = 1;
    g[2 + n + y].push_back(1);
    g[1].push_back(2 + n + y);
    capacity[2 + n + y][1] = 1;
    g[2 + x].push_back(2 + n + y);
    g[2 + n + y].push_back(2 + x);
    capacity[2 + x][2 + n + y] = 1;
  }

  cout << maxFlow(0, 1) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  
  while (cin >> n >> m >> k) {
    solve();
  }

  return 0;
}
