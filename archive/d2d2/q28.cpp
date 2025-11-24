// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

int k, n;
vector<int> g[100100];

int dijkstra() {
  vector<int> dist(k, LLONG_MAX);
  set<array<int, 2>> xt;
  dist[0] = 0;
  xt.insert({0, 0});
  while (!xt.empty()) {
    int node = (*xt.begin())[1];
    xt.erase(xt.begin());
    for (auto v : g[node]) {
      int tmp = abs(node - v) * 5, y = (dist[node] + tmp - 1) / tmp;
      if (v < node && (y % 2 == 0)) y++;
      if (v > node && (y & 1)) y++;
      int time = tmp * y + tmp;
      pr(v, node, tmp, time, y);
      if (dist[v] > time) {
        xt.erase({dist[v], v});
        dist[v] = time;
        xt.insert({dist[v], v});
      }
    }
    pr(dist);
  }
  return dist[k - 1];
}


void solve() {
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  cout << dijkstra() << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
 