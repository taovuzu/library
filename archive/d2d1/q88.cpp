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

int n, r, q;

void solve() {
  vector<vector<int>> a(105, vector<int> (105, LLONG_MAX)), b(105, vector<int> (105, LLONG_MAX));
  vector<array<int, 3>> edges(r);
  for (int i = 0; i < n; i++) a[i][i] = 0;
  for (int i = 0; i < r; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    a[edges[i][0]][edges[i][1]] = a[edges[i][1]][edges[i][0]] = edges[i][2];
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (a[i][k] == LLONG_MAX) continue;
      for (int j = 0; j < n; j++) {
        if (a[k][j] == LLONG_MAX) continue;
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int ans = LLONG_MAX;
      for (int k = 0; k < r; k++) {
        int u = edges[k][0], v = edges[k][1], w = edges[k][2];
        if (a[i][u] != LLONG_MAX && a[v][j] != LLONG_MAX ) {
          int dis = a[i][u] + w + a[v][j];
          if (dis > a[i][j]) ans = min(ans, dis);
        }
        if (a[i][v] != LLONG_MAX && a[u][j] != LLONG_MAX ) {
          int dis = a[i][v] + w + a[u][j];
          if (dis > a[i][j]) ans = min(ans, dis);
        }
      }
      b[i][j] = ans;
    }
  }


  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (b[u][v] == LLONG_MAX) cout << "?" << "\n";
    else cout << b[u][v] << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  while (cin >> n >> r){
    cout << "Set #" << tt++ << "\n";
    solve();
  }

  return 0;
}
