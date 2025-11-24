// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

struct node {
  int len, toll;
};

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

  digraph(int _n) : graph<T>(_n) {}

  int add(int from, int to, T cost = T()) {
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

int dijkstra(int k, graph<node> &g) {
  vector<vector<int>> dist(g.n, vector<int> (k + 5, LLONG_MAX));
  dist[0][k] = 0;
  set<array<int, 3>> xt; // len, node, coins_left
  xt.insert({0, 0, k});
  while (!xt.empty()) {
    auto &x = *xt.begin();
    xt.erase(xt.begin());
    int u = x[1], left = x[2];
    for (auto id : g.g[u]) {
      auto &e = g.edges[id];
      if (left - e.cost.toll < 0) continue;
      if (dist[u][left] + e.cost.len < dist[e.to][left - e.cost.toll]) {
        xt.erase({dist[e.to][left - e.cost.toll], e.to, left - e.cost.toll});
        dist[e.to][left - e.cost.toll] = dist[u][left] + e.cost.len;
        xt.insert({dist[e.to][left - e.cost.toll], e.to, left - e.cost.toll});
      }
    }
  }
  int ans = LLONG_MAX;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, dist[g.n - 1][i]);
  }
  return ans == LLONG_MAX ? -1 : ans;
}

void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  digraph<node> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, len, toll;
    cin >> u >> v >> len >> toll;
    struct node tmp = {len, toll};
    g.add(u - 1, v - 1, tmp);
  }
  cout << dijkstra(k, g) << "\n";
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
