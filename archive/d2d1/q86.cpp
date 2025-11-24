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

void solve() {
  int n, m, ans = 0, j = 0;
  cin >> n >> m;

  int cntZero = n;
  vector<int> inDeg(n + 5);
  set<int> xt;
  vector<array<int, 2>> a(m);
  vector<bool> visit(n, false);
  digraph<int> g(n);

  for (int i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1];
    --a[i][0], --a[i][1];
  }

  auto add = [&](){
    while (cntZero != 1 && j < m) {
      if (visit[a[j][1]] || visit[a[j][0]]) {
        j++;
        continue;
      }
      inDeg[a[j][0]]++;
      g.add(a[j][1], a[j][0]);
      if (inDeg[a[j][0]] == 1) {
        cntZero--;
        xt.erase(a[j][0]);
      }
      j++;
    }
  };

  add();
  for (int i = 0; i < n; i++) {
    if (inDeg[i] == 0) {
      xt.insert(i);
    }
  }
  
  while(cntZero != 0) {
    if (xt.size() > 1) {
      ans = -1;
      break;
    }
    int node = *xt.begin();
    xt.erase(xt.begin());
    cntZero--;
    visit[node] = true;
    for (auto id : g.g[node]) {
      auto &e = g.edges[id];
      if (visit[e.to]) continue;
      inDeg[e.to]--;
      if (inDeg[e.to] == 0) {
        xt.insert(e.to);
        cntZero++;
      }
    }
    if (xt.size() > 1) add();
  }

  cout << (ans == -1 ? -1 : j);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
