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

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
  // returns numeric_limits<T>::max() if there's no path
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    cin.ignore();
    undigraph<int> g(500);
    for(int i = 0; i < 500; i+=5){
      for(int j = i; j < i + 5; j++){
        for(int l = j + 1; l < i + 5; l++){
          if(j < 5) g.add(j, l, 0);
          else g.add(j, l, 60);
        }
      }
    }

    for(int i = 0; i < n; i++){
      string s;
      getline(cin, s);
      string ch = "";
      vector<int> b;
      for(int j = 0; j < s.size(); j++){
        if(s[j] == ' ' || j + 1 == s.size()){
          if (j + 1 == s.size() && s[j] != ' ')  ch += s[j];
          int num = stoi(ch);
          ch = "";
          b.push_back(num);
        }
        else ch += s[j];
      }
      for(int j = 0; j + 1 < b.size(); j++){
        int from = b[j] * 5 + i, to = b[j + 1] * 5 + i, cost = a[i] * (to - from) / 5;
        g.add(from, to , cost);
      }
    }

    vector<int> dist = dijkstra(g, 0);
    int ans = min({dist[k * 5], dist[k * 5 + 1], dist[k * 5 + 2], dist[k * 5 + 3], dist[k * 5 + 4]});
    cout << (ans < LLONG_MAX ? to_string(ans) : "IMPOSSIBLE") << "\n";

  }

  return 0;
}