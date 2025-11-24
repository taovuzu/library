// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
    int l = 0;
    int r = 0;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

int dfs(int node, int par, graph<int> &g) {
  int ans = 1;
  for (auto id : g.g[node]) {
    auto &e = g.edges[id];
    int to = e.from ^ e.to ^ node;
    if (to == par) continue;
    e.l = dfs(to, node, g);
    e.r = g.n - e.l;
    ans += e.l;
  }
  return ans;
}

void solve() {
  int n, q;
  cin >> n;
  undigraph<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.add(u - 1, v - 1, w);
  }
  dfs(0, -1, g);
  double ans = 0, mul = 3.0 / (n * (n - 1));
  for (int i = 0; i < n - 1; i++) {
    auto &e = g.edges[i];
    ans += e.cost * e.l * e.r * 2;
  }
  cin >> q;
  while (q--) {
    int id, cost;
    cin >> id >> cost;
    auto &e = g.edges[id - 1];
    ans -= e.cost * e.l * e.r * 2;
    ans += cost * e.l * e.r * 2;
    e.cost = cost;
    cout << setprecision(12) << fixed << (ans * mul)  << "\n";
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
