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

const int mod = 1e9 + 7;
int d, n, ans;
vector<int> a(2005);

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
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

int dfs(int node, int par, int start, graph<int>& g) {
  int res = 1;
  vector<int> tmp = {1};
  for (auto id : g.g[node]) {
    auto &e = g.edges[id];
    int to = e.from ^ e.to ^ node;
    if (to == par || a[to] > a[start] || (a[start] - a[to]) > d ) continue;
    if (a[to] == a[start] && to <= start) continue;
    int x = dfs(to, node, start, g);
    tmp.push_back(x + 1);
  }
  for (auto x : tmp) {
    res = (res * x) % mod;
  }
  return res;
}

void solve() {
  cin >> d >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  undigraph<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1);
  }

  for (int i = 0; i < n; i++) {
    ans = (ans + dfs(i, -1, i, g)) % mod;
  }

  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
