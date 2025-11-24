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
double a[20][20], dp[1 << 18];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  dp[(1 << n) - 1] = 1;

  for (int s = (1 << n) - 1; s; s--) {
    int cnt = __builtin_popcount(s);
    for (int i = 0; i < n; i++) {
      if (!(s >> i & 1)) continue;
      for (int j = i + 1; j < n; j++) {
        if (!(s >> j & 1)) continue;
        dp[s ^ (1 << j)] += dp[s] * a[i][j] / (cnt * (cnt - 1) / 2.0);
        dp[s ^ (1 << i)] += dp[s] * a[j][i] / (cnt * (cnt - 1) / 2.0);
      }
    }
  }


  for (int i = 0; i < n; i++) {
    cout << setprecision(9) << fixed << dp[1 << i] << " \n"[i == n - 1];
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
