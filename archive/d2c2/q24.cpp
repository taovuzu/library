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
class graph{
  public:
  struct edge{
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n){
    g.resize(n);
  }

  virtual int add(int to, int from, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T> (_n){
  }

  int add(int x, int y, T c){
    assert(0 <= x && x < n && 0 <= y && y < n);
    int id = (int) edges.size();
    edges.push_back({x, y, c});
    g[x].push_back(id);
    g[y].push_back(id);
    return id;
  }
};

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start){
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  dist[start] = 0;
  set<pair<T, int>> s;
  s.emplace(dist[start], start);

  while(!s.empty()){
    int i = s.begin()->second;
    s.erase(s.begin());
    for(auto id : g.g[i]){
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if(dist[to] > dist[i] + e.cost){
        s.erase({dist[to], to});
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  int ttt = 0;
  while (tt--) {
    ttt++;
    int v, e, sr, ds;
    cin >> v >> e >> sr >> ds;
    undigraph<int> g(v);
    for(int i = 0; i < e; i++){
      int from, to, cost;
      cin >> from >> to >> cost;
      g.add(from, to, cost);
    }
    vector<int> dist = dijkstra(g, sr);
    cout << "Case #" << ttt <<": " << (dist[ds] < LLONG_MAX ? to_string(dist[ds]) : "unreachable") << "\n";
  }

  return 0;
}
