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
  int n, q;
  cin >> n >> q;
  vector<int> val(n), color(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    vector<int> dp(n + 1, -1e18);
    dp[0] = 0;
    int ans = 0, maxi = 0, maxi1 = 0;
    for (int i = 0; i < n; i++) {
      int maxi2 = (maxi == color[i] ? dp[maxi1] : dp[maxi]);
      int same = dp[color[i]] + max(val[i] * x , 0LL);
      int diff = val[i] * y + maxi2;
      dp[color[i]] = max(same, diff);
      ans = max(ans, dp[color[i]]);
      if (color[i] == maxi) continue;
      if (dp[color[i]] > dp[maxi] ) {
          maxi1 = maxi;
          maxi = color[i];
      }
      else if (dp[color[i]] > dp[maxi1]) {
        maxi1 = color[i];
      }
    }
    cout << ans << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
