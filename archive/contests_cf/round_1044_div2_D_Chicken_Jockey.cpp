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
vector<int> a(200200), dp(200200);

int rec(int idx) {
  if (idx >= n) return 0;
  if (dp[idx] != -1) return dp[idx];
  int ans = LLONG_MAX;
  if (idx < n - 1) ans = min(ans, a[idx] - min(a[idx + 1], idx + 1) + rec(idx + 1));
  ans = min(ans, a[idx] + rec(idx + 1));
  return dp[idx] = ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    dp[i] = -1;
    cin >> a[i];
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
