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

int n, m, st, tar;
vector dis(1005, vector<int> (1005, LLONG_MAX));
vector driver(1005, array<int, 2>());

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

void dijkstra(const graph<int>& g, int start) {
  vector<int> dist(g.n, LLONG_MAX);
  dist[start] = 0;
  set<array<int, 2>> xt;
  xt.insert({0, start});
  while (!xt.empty()) {
    int node = (*xt.begin())[1];
    xt.erase(xt.begin());
    for (auto id : g.g[node]) {
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ node;
      if (dist[node] + e.cost < dist[to]) {
        xt.erase({dist[node], to});
        dist[to] = dist[node] + e.cost;
        xt.insert({dist[to] + e.cost, to});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    dis[start][i] = dist[i];
  }
}

void solve() {
  cin >> n >> m >> st >> tar;
  st--, tar--;
  undigraph<int> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.add(u - 1, v - 1, w);
  }
  for (int i = 0; i < n; i++) {
    cin >> driver[i][0] >> driver[i][1]; // ti, ci
    dijkstra(g, i);
  }

  digraph<int> g1(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (dis[i][j] <= driver[i][0]) g1.add(i, j, driver[i][1]);
    }
  }

  dijkstra(g1, st);
  cout << (dis[st][tar] == LLONG_MAX ? -1 : dis[st][tar]);

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
