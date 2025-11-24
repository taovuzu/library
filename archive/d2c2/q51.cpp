#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
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

  graph(int _n) : n(_n) { g.resize(n); }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {}

  int add(int from, int to, T cost) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int)edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
pair<int, int> dijkstra(graph<T> &g, int start, int end) {
  assert(0 <= start && start < g.n);
  vector<pair<int, int>> dist(
      g.n, make_pair(numeric_limits<int>::max(), numeric_limits<int>::max()));
  dist[start] = make_pair(0, 0);
  set<pair<T, int>> s;
  s.emplace(dist[start], start);

  while (!s.empty()) {
    int i = s.begin()->second;
    s.erase(s.begin());
    for (auto id : g.g[i]) {
      typename graph<T>::edge &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i].first + e.cost.first < dist[to].first) {
        s.erase(make_pair(dist[to], to));
        dist[to] = make_pair(dist[i].first + e.cost.first,
                             dist[i].second + e.cost.second);
        s.emplace(dist[to], to);
      } else if (dist[i].first + e.cost.first == dist[to].first &&
                 dist[i].second + e.cost.second < dist[to].second) {
        s.erase(make_pair(dist[to], to));
        dist[to] = make_pair(dist[i].first + e.cost.first,
                             dist[i].second + e.cost.second);
        s.emplace(dist[to], to);
      }
    }
  }
  return dist[end];
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    undigraph<pair<int, int>> g(x);

    for (int i = 0; i < y; i++) {
      int u, v, t, l;
      cin >> u >> v >> t >> l;
      u--, v--;
      g.add(u, v, {t, l});
    }

    int q;
    cin >> q;
    while (q--) {
      int start, dest;
      cin >> start >> dest;
      start--, dest--;

      pair<int, int> ans = dijkstra(g, start, dest);
      if (ans.first == LLONG_MAX) {
        cout << "No Path." << "\n";
      } else {
        cout << "Distance and time to reach destination is " << ans.second
             << " & " << ans.first << "." << "\n";
      }
    }
    if (tt) cout << "\n";
  }

  return 0;
}
