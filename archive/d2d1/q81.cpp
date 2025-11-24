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

int n, k;
int dp[1 << 12][100];

int rec(int mask, int inv) {
  if (mask == (1 << n) - 1) return inv == k;
  if (inv > k) return 0;

  if(dp[mask][inv] != -1) return dp[mask][inv];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      int cnt = 0;
      for (int j = i + 1; j < n; j++) {
        if (mask & (1 << j)) cnt++;
      }
    ans += rec(mask | (1 << i), inv + cnt);
    }
  }

  return dp[mask][inv] = ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = -1;
    }
  }
  cout << rec(0, 0) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
