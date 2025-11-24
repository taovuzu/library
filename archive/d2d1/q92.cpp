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

int n, ans = LLONG_MIN;
vector<int> a(200200), sum(200200);

void dfs(int node, int par, graph<int> &g) {
  sum[node] = a[node];
  a[node] = LLONG_MIN;
  int best1 = LLONG_MIN, best2 = LLONG_MIN;
  for (int id : g.g[node]) {
    auto e = g.edges[id];
    int to = e.from ^ e.to ^ node;
    if (to == par) continue;
    dfs(to, node, g);
    sum[node] += sum[to];
    a[node] = max(a[to], a[node]);
    int val = a[to];
    if (best1 < val) swap(best1, val);
    if (best2 < val) swap(best2, val);
  }
  if (best2 != LLONG_MIN) ans = max(ans, best1 + best2);
  a[node] = max(sum[node], a[node]);
}


void solve() {
  cin >> n;
  undigraph<int> g(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1);
  }

  dfs(0, -1, g);
  
  if (ans == LLONG_MIN) {
    cout << "Impossible" << "\n";
  }
  else cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
