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

// returns (diameter, max height);
template <typename T>
pair<int, int> diameter(int node, int par, graph<T> &g) {
  int dia = 0;
  
  array<int, 3> a = {-1, -1, -1};
  for (int i = 0; i < g.g[node].size(); i++) {
    int id = g.g[node][i];
    int to = g.edges[id].from ^ g.edges[id].to ^ node;
    if(to == par) continue;

    pair<int, int> p = diameter(to, node, g);
    a[0] = p.second + 1;
    dia = max(dia, p.first);
    sort(a.begin(), a.end());
  }

  for (int i = 0; i < 3; i++) {
    if (a[i] == - 1) a[i] = 0;
  }
  dia = max(dia, a[1] + a[2]);

  return {dia, a[2]};
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  undigraph<int> g(n);
  for (int i = 0; i < n - 1 ; i++) {
    int u, v;
    cin >> u >> v;
    g.add(u - 1, v - 1);
  }

  pair<int, int> ans = diameter(0, -1, g);
  cout << ans.first << "\n";

  return 0;
}