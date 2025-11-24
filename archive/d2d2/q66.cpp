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

int n, m, v;
vector<vector<int>> g(505), capacity(505, vector<int> (505));

int bfs(int src, int sink, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});

  while(!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto nv : g[u]) {
      if (par[nv] == -1 && capacity[u][nv]) {
        int new_flow = min(flow, capacity[u][nv]);
        par[nv] = u;
        if (nv == sink) return new_flow;
        qu.push({nv, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow(int src, int sink) {
  vector<int> par(v + 5);
  int flow = 0, new_flow = 0;
  
  while (new_flow = bfs(src, sink, par)) {
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[curr][prev] += new_flow;
      capacity[prev][curr] -= new_flow;
      curr = prev;
    }
  }

  return flow;
}

void solve() {
  cin >> n >> m >> v;
  for (int i = 0; i < v + 5; i++) {
    g[i].clear();
    for (int j = 0; j < v + 5; j++) {
      capacity[i][j] = 0;
    }
  }

  vector<array<int, 2>> a;
  for (int i = 0; i < v; i++) {
    string s, s1;
    cin >> s >> s1;
    int u = stoi(s.substr(1)) + ((s[0] == 'C') ? 0 : n);
    int nv = stoi(s1.substr(1)) + ((s1[0] == 'C') ? 0 : n);
    a.push_back({u, nv});
  }

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      if (a[i][0] > n && a[j][0] <= n) continue;
      if (a[i][0] == a[j][1] || a[i][1] == a[j][0]) {
        g[i + 1].push_back(j + 1);
        g[j + 1].push_back(i + 1);
        capacity[i + 1][j + 1] = 1;
      }
    }
    if (a[i][0] <= n) {
      g[0].push_back(i + 1);
      g[i + 1].push_back(0);
      capacity[0][i + 1] = 1;
    }
    else {
      g[i + 1].push_back(v + 1);
      g[v + 1].push_back(i + 1);
      capacity[i + 1][v + 1] = 1;
    }
  }

  cout << v - maxFlow(0, v + 1) << "\n";
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
