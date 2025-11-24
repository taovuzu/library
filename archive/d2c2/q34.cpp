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


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
    if (a[i] != -1) {
      for (int j = 0; j < m; j++) {
        b[i][j] = LLONG_MAX;
      }
      b[i][a[i]] = 0;
    }
  }

  vector<vector<int>> dp(k, vector<int>(m, LLONG_MAX));
  dp[0] = b[0];

  for (int i = 1; i < n; i++) {
    vector<vector<int>> newdp(k, vector<int>(m, LLONG_MAX));
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < m; l++) {
        for (int ix = 0; ix < m; ix++) {
          int nj = j + (l != ix);
          if (nj < k && dp[j][l] != LLONG_MAX && b[i][ix] != LLONG_MAX) {
            newdp[nj][ix] = min(newdp[nj][ix], dp[j][l] + b[i][ix]);
          }
        }
      }
    }
    swap(dp, newdp);
  }

  int ans = *min_element(dp[k - 1].begin(), dp[k - 1].end());
  ans = (ans == LLONG_MAX ? -1 : ans);

  cout << ans << "\n";

  return 0;
}
