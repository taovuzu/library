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

vector<vector<int>> g(38), capacity(38, vector<int> (38));

int bfs(int src, int sink, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});

  while (!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto v : g[u]) {
      if (par[v] == -1 && capacity[u][v] > 0) {
        int new_flow = min(flow, capacity[u][v]);
        par[v] = u;
        if (v == sink) return new_flow;
        qu.push({v, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow(int src, int sink) {
  vector<int> par(38);
  int flow = 0, new_flow = 0;

  while (new_flow = bfs(src, sink, par)) {
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[curr][prev] += new_flow;
      capacity[prev][curr] -= new_flow;
      curr = prev;
    }
  }

  return flow;
}

void solve() {
  while(true) {
    for (int i = 0; i < 38; i++) {
      g[i].clear();
      fill(capacity[i].begin(), capacity[i].end(), 0);
    }

    for (int i = 1; i <= 26; i++) {
      g[0].push_back(i);
      g[i].push_back(0);
    }
    for (int i = 27; i < 37; i++) {
      g[i].push_back(37);
      g[37].push_back(i);
    }
    for (int i = 27; i < 37; i++) {
      capacity[i][37] = 1;
    }

    int sum = 0;
    string s;
    if (!getline(cin, s)) break;
    do {
      if (s == "") break;
      int u = s[0] - 'A' + 1, w = s[1] - '0';
      capacity[0][u] = w;
      sum += w;
      for (int i = 3; i < s.size() - 1 && s[i] != ';'; i++) {
        int v = s[i] - '0' + 27;
        g[u].push_back(v);
        g[v].push_back(u);
        capacity[u][v] = LLONG_MAX;
      }
    } while (getline(cin, s));

    if (maxFlow(0, 37) != sum) {
      cout << "!" << "\n";
    }
    else {
      for (int i = 27; i < 37; i++) {
        bool flag = false;
        for (int j = 1; j <= 26; j++) {
          if (capacity[i][j] == 1) {
            char ch = 'A' + j - 1;
            cout << ch;
            flag = true;
            break;
          }
        }
        if (!flag) cout << "_";
      }
      cout << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
