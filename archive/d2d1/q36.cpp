// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य
// तालान् उद्घाटयति। उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् भाशवँ उखँ चतुर्थः
// प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप
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

vector<int> ans;

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
class digraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  digraph(int _n) : graph<T>(_n) {}

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int)edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto& e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }
};

int dfs(int node, int depth, int cnt, graph<int>& g) {
  int maxi = (depth - cnt) * 2 >= depth ? 0 : ((depth + 1) / 2 - (depth - cnt));
  for (auto id : g.g[node]) {
    auto& e = g.edges[id];
    int x = dfs(e.to, depth + 1, cnt + e.cost, g);
    if (x > cnt) {
      ans.push_back(id + 1);
      x--;
    }
    maxi = max(x, maxi);
  }
  return maxi;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  digraph<int> g(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    string s, s1;
    cin >> x >> y >> s;
    if (s == "almost") {
      cin >> s1;
      g.add(y - 1, x - 1, 1);
    } else {
      g.add(y - 1, x - 1, 0);
    }
  }

  dfs(0, 0, 0, g);

  cout << ans.size() << "\n";
  for (auto num : ans) {
    cout << num << " ";
  }

  return 0;
}
