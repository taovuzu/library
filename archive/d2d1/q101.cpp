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

array<int, 2> dfs(int node, int dest, array<int, 2> ans, int &vis, graph<array<int, 2>> &g) {
  vis |= (1 << node);
  if (node == dest) return ans;
  for (auto id : g.g[node]) {
    auto &e = g.edges[id];
    if (vis & (1 << e.to)) continue;
    int hcf = __gcd(ans[0] * e.cost[0], ans[1] * e.cost[1]);
    auto tmp = dfs(e.to, dest, {(ans[0] * e.cost[0]) / hcf, (ans[1] * e.cost[1]) / hcf}, vis, g);
    if (vis & (1LL << dest)) return tmp;
  }
  return {0, 0};
}

void solve() {
  map<string, int> mp;
  digraph<array<int, 2>> g(60);
  char ch;
  string s, s1;
  int x, y;
  while (cin >> ch && ch != '.') {
    if (ch == '!') {
      cin >> x >> s >> ch >> y >> s1;
      if (mp.find(s) == mp.end()) {
        mp[s] = mp.size();
      }
      if (mp.find(s1) == mp.end()) {
        mp[s1] = mp.size();
      }
      g.add(mp[s], mp[s1], {y, x});
      g.add(mp[s1], mp[s], {x, y});
    }
    else {
      cin >> s >> ch >> s1;
      if (mp.find(s) == mp.end() || mp.find(s1) == mp.end()) {
        
        cout << "? " << s << " = ? " << s1 << "\n";
        continue;
      }
      int vis = 0;
      auto ans = dfs(mp[s], mp[s1], {1, 1}, vis, g);
      if (ans[0] == 0 && ans[1] == 0) {
        cout << "? " << s << " = ? " << s1 << "\n";
      } else {
        int hcf = __gcd(ans[0], ans[1]);
        cout << ans[1] / hcf << " " << s << " = " << ans[0] / hcf << " " << s1 << "\n";
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
