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
class digraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }
};

int n, l, r;

void dfs(int node, int par, int flag, graph<int> &g, vector<int> &a) {
  for (auto id : g.g[node]) {
    auto &e = g.edges[id];
    if (e.to == par) continue;
    dfs(e.to, node, e.cost, g, a);
  }
  a[node] = flag ? r-- : l++;
}

void solve() {
  cin >> n;
  digraph<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    g.add(u - 1, v - 1, (y >= x));
    g.add(v - 1, u - 1, (x >= y));
  }
  l = 1, r = n;
  vector<int> a(n);
  dfs(0, -1, 0, g, a);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
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
