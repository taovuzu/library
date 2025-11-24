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

int n;
vector<vector<int>> cap(205, vector<int> (205)), g(205);

int bfs(int s, int t, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[s] = -2;
  queue<array<int, 2>> qu;
  qu.push({s, LLONG_MAX});
  
  while (!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto v : g[u]) {
      if (par[v] == -1 && cap[u][v]) {
        par[v] = u;
        int new_flow = min(flow, cap[u][v]);
        if (v == t) return new_flow;
        qu.push({v, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow(int s, int t) {
  vector<int> par((n << 1) + 2);
  int new_flow , flow = 0;
  
  while (new_flow = bfs(s, t, par)) {
    flow += new_flow;
    int curr = t;
    while (curr != s) {
      int prev = par[curr];
      cap[prev][curr] -= new_flow;
      cap[curr][prev] += new_flow;
      curr = prev;
    }
  }

  return flow;
}

void solve() {
  for (int i = 0; i <= (n << 1) + 1; i++) {
    g[i].clear();
    for (int j = 0; j <= (n << 1) + 1; j++) {
      cap[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cap[i][n + i] = cap[n + i][i] = x;
    g[i].push_back(n + i);
    g[n + i].push_back(i);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[n + u].push_back(v);
    g[v].push_back(n + u);
    cap[n + u][v] = w;
  }

  int k0, k1;
  cin >> k0 >> k1;
  for (int i = 0; i < k0 + k1; i++) {
    int x;
    cin >> x;
    if (i < k0) {
      g[0].push_back(x);
      g[x].push_back(0);
      cap[0][x] = LLONG_MAX;
    }
    else {
      g[n + x].push_back((n << 1) + 1);
      g[(n << 1) + 1].push_back(n + x);
      cap[n + x][(n << 1) + 1] = LLONG_MAX;
    } 
  }

  cout << maxFlow(0, (n << 1) + 1) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n) {
    solve();
  }

  return 0;
}
