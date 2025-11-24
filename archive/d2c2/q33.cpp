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

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n){
  }

  int  add(int from, int to, T cost = 0){
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
void dfs(undigraph<T> &g, vector<int> &val, vector<int> &ans, bool x, bool y, int parent, int node){
  if(val[node] != x){
    x ^= 1;
    ans.push_back(node + 1);
  }

  for(int i = 0; i < g.g[node].size(); i++){
    int id = g.g[node][i];
    auto &e = g.edges[id];
    int to = e.from ^ e.to ^ node;
    if(to == parent ) continue;
    dfs(g, val, ans, y, x, node, to);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  undigraph<int> g(n);
  vector<int> val(n);
  for(int i = 0; i + 1 < n; i++){
    int u, v;
    cin >> u >> v;
    u--, v--;
    g.add(u, v);
  }

  for(int i = 0; i < n; i++){
    cin >> val[i];
  }

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    val[i] ^= x;
  }

  vector<int> ans;
  dfs(g, val, ans, 0, 0, -1, 0);

  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << "\n";
  }


  return 0;
}
