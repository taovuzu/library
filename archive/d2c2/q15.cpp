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

  int tt = 1;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
      dp[i][i] = 1;
    }
    dp[n][n] = 0;

    for (int l = n - 1; l >= 0; l--) {
      for (int r = l + 1; r < n; r++) {
        if (s[l] == s[r]) {
          dp[l][r] = 1 + dp[l + 1][r] + dp[l][r - 1];
        } else {
          dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
        }
      }
    }

    cout << dp[0][n - 1] << "\n";
  }
  return 0;
}