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
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  digraph(int _n) : graph<T> (_n){
  }

  int add(int from, int to, T cost = 1){
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for(auto &e : edges){
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }
};

template <typename T>
void dfs(digraph<T> &g, vector<int> &order, vector<int> &inDeg,  vector<char> &b){
  if(order.size() == g.n){
    for(int i = 0; i < g.n; i++){
      cout << b[order[i]] << " \n"[i == g.n - 1];
    }
    return ;
  }

  for(int i = 0; i < inDeg.size(); i++){
    if(inDeg[i] == 0){
      order.push_back(i);
      inDeg[i] = -1;
      for(auto id : g.g[i]){
        inDeg[g.edges[id].to]--;
      }
      dfs(g, order, inDeg, b);
      for(auto id : g.g[i]){
        inDeg[g.edges[id].to]++;
      }
      order.pop_back();
      inDeg[i] = 0;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  cin.ignore();
  while (tt--) {
    cin.ignore();
    string s;
    getline(cin, s);

    vector<int> a(26,-1);
    vector<char> b(26,'.');
    int cnt = 0;
    pr(s);
    for(auto ch: s){
      if(ch == ' ') continue;
      else a[ch - 'A'] = cnt, b[cnt] = ch;
      cnt++;
    }

    digraph<int> g(cnt);
    getline(cin, s);
    pr(s);
    string temp = "";
    for(auto ch: s){
      if(ch == ' '){
        int x = a[temp[0] - 'A'], y = a[temp[2] - 'A'];
        temp = "";
        g.add(x, y);
      }
      else temp += ch;
    }
    int x = a[temp[0] - 'A'], y = a[temp[2] - 'A'];
    g.add(x, y);

    vector<int> inDeg(g.n, 0), order;
    bool flag = true;
    for(auto &e : g.edges){
      inDeg[e.to]++;
    }
    for(int i = 0; i < g.n; i++){
      if(inDeg[i] == 0){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "NO" << "\n";
    }
    else{
      dfs(g, order, inDeg, b);
      cout << "\n";
    }

  }

  return 0;
}