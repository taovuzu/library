// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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

template <typename T>
vector<int> find_topsort(const digraph<T> &g) {
  vector<int> deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); id++) {
    deg[g.edges[id].to]++;
  }
  vector<int> x;
  for (int i = 0; i < g.n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.to;
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int) x.size() != g.n) {
    return vector<int>();
  }
  return x;
}

void dfs(int u, int mark, vector<int> &vis, graph<int> &g) {
  if (vis[u] != -1) return;
  vis[u] = mark;

  for (auto id : g.g[u]) {
    auto &e = g.edges[id];
    dfs(e.to, mark, vis, g);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  digraph<int> g(n); // par -> child
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1);
  }
  set<int> xt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    xt.insert(a[i]);
  }

  auto g1 = g.reverse(); // child -> par
  vector<int> top = find_topsort(g1);

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (xt.find(top[i]) != xt.end()) {
      ans.push_back(top[i]);
    }
  }

  bool flag = true;
  vector<int> vis(n, -1);

  for (int i = 0; i < ans.size(); i++) {
    if (vis[ans[i]] == -1) {
      dfs(ans[i], ans[i], vis, g);
    }
  }

  for (int i = 0; i < n; i++) {
    if (vis[i] != a[i]) {
      flag = false;
      break;
    }
  }

  pr(vis, top, ans, a);

  if (!flag) {
    cout << -1 << "\n"; 
  }
  else {
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << "\n";
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
