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

int n, m;
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
        if (sink == v) return new_flow;
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
    pr(new_flow, par);
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[prev][curr] -= new_flow;
      capacity[curr][prev] += new_flow;
      curr = prev;
      pr(curr);
    }
  }

  return flow;
}

void solve() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n + m + 5; i++) {
    g[i].clear();
    for (int j = 0; j < n + m + 5; j++) {
      capacity[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    g[0].push_back(2 + i);
    g[2 + i].push_back(0);
    capacity[0][2 + i] = 1;
  }
  for (int i = 0; i < m; i++) {
    g[2 + n + i].push_back(1);
    g[1].push_back(2 + n + i);
    capacity[2 + n + i][1] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((a[i] != 0 && b[j] % a[i] == 0) || (a[i] == b[j])) {
        g[2 + i].push_back(2 + n + j);
        g[2 + n + j].push_back(2 + i);
        capacity[2 + i][2 + n + j] = 1;
      }
    }
  }

  cout << maxFlow(0, 1) << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    cout << "Case " << t_ << ": ";
    solve();
  }

  return 0;
}
