// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
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

int n, m, k;

void printer(int idx, vector<vector<int>> &level, string &s, vector<string> &ans) {
  if (!k) return;
  if (idx == n) {
    ans.push_back(s);
    k--;
    return;
  }
  for (int i = 0; i < level[idx].size(); i++) {
    if (!k) return;
    s[level[idx][i]] = '1';
    printer(idx + 1, level, s, ans);
    s[level[idx][i]] = '0';
  }
}

void solve() {
  cin >> n >> m >> k;
  undigraph<int> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1);
  }
  vector<vector<int>> level(n);
  vector<int> vis(n, -1);
  vis[0] = 0;
  queue<int> qu;
  qu.push(0);
  int curr = 0;
  while (!qu.empty()) {
    int sz = qu.size();
    while (sz--) {
      int u = qu.front();
      qu.pop();
      for (auto id : g.g[u]) {
        auto &e = g.edges[id];
        int to = e.from ^ e.to ^ u;
        if (vis[to] == -1 || vis[to] == curr + 1) {
          level[to].push_back(id);
        }
        if(vis[to] == -1) {
          vis[to] = curr + 1;
          qu.push(to);
        }
      }
    }
    curr++;
  }
  pr(level);
  vector<string> ans;
  string s(m, '0');
  printer(1, level, s, ans);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
