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

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int)edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

template <typename T>
vector<int> find_mst(const undigraph<T> &g, T &ans) {
  vector<int> order(g.edges.size());
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(),
       [&g](int a, int b) { return g.edges[a].cost < g.edges[b].cost; });
  dsu d(g.n);
  vector<int> ans_list;
  ans = 0;
  for (int id : order) {
    auto &e = g.edges[id];
    if (d.get(e.from) != d.get(e.to)) {
      d.unite(e.from, e.to);
      ans_list.push_back(id);
      ans += e.cost;
    }
  }
  return ans_list;
  // returns edge ids of minimum "spanning" forest
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 1, tt1;
  cin >> tt;
  tt1 = 0;
  while (tt--) {
    tt1++;
    int v, e;
    cin >> v >> e;
    undigraph<int> graph(v);  
    for (int i = 0; i < e; i++) {
      int x, y, c;
      cin >> x >> y >> c;
      graph.add(x - 1, y - 1, c); 
    }

    int ans = 0;
    vector<int> mst = find_mst(graph, ans);

    cout << "Case #" << tt1 << " : ";
    if (mst.size()!=v-1) {
      cout << "No way" << '\n';
    } else if (e == v - 1) {
      cout << "No second way" << '\n';
    } else {
      int second_best = LLONG_MAX;

      for (int i = 0; i < mst.size(); i++) {
        undigraph<int> temp_graph(v);
        for (int j = 0; j < e; j++) {
          if (j == mst[i]) continue;  
          auto &edge = graph.edges[j];
          temp_graph.add(edge.from, edge.to, edge.cost);
        }

        int temp_ans = 0;
        vector<int> new_mst = find_mst(temp_graph, temp_ans);

        if (new_mst.size() == v - 1) {  
          second_best = min(second_best, temp_ans);
        }
      }

      cout<<second_best<<"\n";
    }
  }

  return 0;
}
