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

map<int, vector<int>> mp;

int dfs(int node, int par, graph<int> &g) {
  int ans = 0;
  for (auto id : g.g[node]) {
    auto &e = g.edges[id];
    if (e.to == par) continue;
    ans += dfs(e.to, node, g) + (e.cost == -1);
  }
  return ans;
}

vector<int> a;
int ans;

void dfs1(int node, int par, int cost, graph<int> &g) {
  if (cost == ans) a.push_back(node + 1);
  else if (cost < ans) {
    a.clear();
    a.push_back(node + 1);
    ans = cost;
  }

  for (auto id : g.g[node]) {
    auto &e = g.edges[id];
    if (e.to == par) continue;
    dfs1(e.to, node, cost + e.cost, g);
  }
}

void solve() {
  int n;
  cin >> n;

  digraph<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1, 1);
    g.add(v - 1, u - 1, -1);
  }

  ans = dfs(0, -1, g);
  dfs1(0, -1, ans, g);

  sort(a.begin(), a.end());
  cout << ans << "\n";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " \n"[i == n - 1];
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
