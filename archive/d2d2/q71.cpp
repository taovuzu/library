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

int n, m;
vector<vector<int>> g(215), capacity(215, vector<int> (215)), capacity1(215, vector<int> (215));

int bfs(int src, int sink, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});
  
  while(!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();

    for (auto v : g[u]) {
      if (par[v] == - 1 && capacity[u][v]) {
        int new_flow = min(flow, capacity[u][v]);
        par[v] = u;
        if(v == sink) return new_flow;
        qu.push({v, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow(int src, int sink) {
  vector<int> par(n + m + 5);
  int flow = 0, new_flow = 0;

  while (new_flow = bfs(src, sink, par)) {
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[prev][curr] -= new_flow;
      capacity[curr][prev] += new_flow;
      curr = prev;
    }
  }

  return flow;
}

bool feas(long double x, long double y, long double w, long double z, long double x1, long double y1) {
  auto dist_sq = [](long double p1, long double q1, long double p2, long double q2) {
      return (p2 - p1) * (p2 - p1) + (q2 - q1) * (q2 - q1);
  };
  long double dist_Bob = sqrtl(dist_sq(x, y, w, z));          // Bob's segment: a[i] to a[i+1]
  long double dist_Ralph = sqrtl(dist_sq(x, y, x1, y1))      // Ralph's path: a[i] to b[j]
                         + sqrtl(dist_sq(x1, y1, w, z));    // Ralph's path: b[j] to a[i+1]
  return dist_Ralph <= 2.0 * dist_Bob + 1e-9; 
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i <= n + m + 5; i++) {
    g[i].clear();
    for (int j = 0; j <= n + m + 5; j++) {
      capacity[i][j] = capacity1[i][j] = 0;
    }
  }

  vector<array<int, 2>> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    g[0].push_back(i + 1);
    g[i + 1].push_back(0);
    capacity[0][i + 1] = capacity1[0][i + 1]= 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i][0] >> b[i][1];
    g[n + i + 1].push_back(n + m + 1);
    g[n + m + 1].push_back(n + i + 1);
    capacity[n + i + 1][n + m + 1] = capacity1[n + i + 1][n + m + 1] = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (feas(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1], b[j][0], b[j][1])) {
        g[i + 1].push_back(n + j + 1);
        g[n + j + 1].push_back(i + 1);
        capacity[i + 1][n + j + 1] = capacity1[i + 1][n + j + 1] = 1;
      }
    }
  }

  cout << n + maxFlow(0, n + m + 1) << "\n";

  for (int i = 0; i < n; i++) {
    cout << a[i][0] << " " << a[i][1] << " \n"[i == n - 1];
    for (int j = 0; j < m; j++) {
      if (capacity1[i + 1][n + j + 1] && (capacity[i + 1][n + j + 1] == 0)) {
        cout << b[j][0] << " " << b[j][1] << " ";
        break;
      }
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    if (t_ != 1) cout << "\n";
    solve();
  }

  return 0;
}
