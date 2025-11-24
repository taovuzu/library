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

// return (dia, max hieght);
template <typename T>
pair<int, int> diameter(int node, int par, graph<T> &g) {
  int dia = 0;
  vector<int> a = {0, 0, 0};
  for (int i = 0; i < g.g[node].size(); i++) {
    int id = g.g[node][i];
    int to = g.edges[id].from ^ g.edges[id].to ^ node;
    if (to == par) continue;

    pair<int, int> p = diameter(to, node, g);
    dia = max(p.first, dia);
    sort(a.begin(), a.end());
    a[0] = p.second + g.edges[id].cost;
  }

  sort(a.begin(), a.end());
  dia = max(dia, a[1] + a[2]);

  return {dia, a[2]};
}

template <typename T>
pair<int, int> bfs(int node, graph<T> &g) {
  int farNode = node;
  int maxDis = 0;

  queue<int> q;
  vector<bool> vis(g.n, false);
  vis[node] = true;
  q.push(node);
  q.push(0);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    int dis = q.front();
    q.pop();
    if (dis > maxDis) {
      maxDis = dis;
      farNode = curr;
    }
    for (int i = 0; i < g.g[curr].size(); i++) {
      int id = g.g[curr][i];
      int to = g.edges[id].from ^ g.edges[id].to ^ curr;
      if(vis[to]) continue;
      vis[to] = true;
      int newDis = g.edges[id].cost + dis;
      q.push(to);
      q.push(newDis);
    }
  }

  return {maxDis, farNode};

}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string line;
  vector<tuple<int, int, int>> edges;
  int max_node = 0;

  while (getline(cin, line)) {
    if (line.empty()) {
      if (!edges.empty()) {
        undigraph<int> g(max_node); 

        for (auto [u, v, w] : edges) {
          g.add(u, v, w);
        }

        auto [ignore, node1] = bfs(0, g);
        auto [dia, temp] = bfs(node1, g);

        cout << dia << "\n";

        edges.clear();
        max_node = 0;
      }
    } else {
      istringstream iss(line);
      int u, v, w;
      if (iss >> u >> v >> w) {
        edges.emplace_back(u - 1, v - 1, w);
        max_node = max({max_node, u, v});
      }
    }
  }

  // Handle the last graph if input doesn't end with blank line
  if (!edges.empty()) {
    undigraph<int> g(max_node + 1);
    for (auto [u, v, w] : edges) {
      g.add(u, v, w);
    }
    auto [ignore, node1] = bfs(0, g);
    auto [dia, temp] = bfs(node1, g);

    cout << dia << "\n";
  }

  return 0;
}