// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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

int n, m;
vector<int> b(200100);

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

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  dist[start] = 0;

  set<pair<T, array<int, 2>>> s;
  s.emplace(dist[start], array<int, 2>{start, b[start]});

  while (!s.empty()) {
    auto [i, maxi] = s.begin()->second;
    s.erase(s.begin());

    for (int id : g.g[i]) {
      const auto &e = g.edges[id];
      int to = e.to;
      if (max(dist[i], e.cost) < dist[to] && maxi >= e.cost) {
        s.erase({dist[to], array<int, 2>{to, maxi + b[to]}});
        dist[to] = max(dist[i], e.cost);
        s.emplace(dist[to], array<int, 2>{to, maxi + b[to]});
      }
    }
  }

  return dist;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    digraph<int> g(n);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g.add(u - 1, v - 1, w);
    }

    vector<int> ans = dijkstra(g, 0);
    cout << (ans[n - 1] == LLONG_MAX ? -1 : ans[n - 1]) << "\n";
  }

  return 0;
}
