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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), dp(n + 1);
  vector<vector<int>> freq(n + 1, {0});
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]].push_back(i);
    int sz = freq[a[i]].size();
    dp[i] = ans;
    if (sz > a[i] && dp[i] < dp[freq[a[i]][sz - a[i]] - 1] + a[i]) {
      pr(freq[a[i]][sz - a[i]]);
      dp[i] =  dp[freq[a[i]][sz - a[i]] - 1] + a[i];
    }
    ans = max(ans, dp[i]);
    pr(i, ans);
    pr(dp);
    pr(freq);
  }
  cout << ans << "\n";
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
