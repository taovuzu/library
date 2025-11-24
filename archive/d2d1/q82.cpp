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

int n;
int a[20][20];
int dp[1 << 20];

int rec(int mask) {
  int idx = __builtin_popcount(mask);
  if (idx == n) return 1;
  if (dp[mask] != -1 ) return dp[mask];

  int ans = 0;
  for (int j = 0; j < n; j++) {
    if ((mask & (1 << j)) == 0 && a[idx][j]) {
      ans += rec(mask | (1 << j));
    }
  }
  return dp[mask] = ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < (1 << 20); i++) {
    for (int j = 0; j < 20; j++) {
      dp[i][j] = -1;
    }
  }

  cout << rec(0) << "\n";

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
