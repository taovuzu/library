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

void solve() {
  int n, k, maxi;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> k >> maxi;
  int ans = LLONG_MIN;
  vector dp(n + 1, vector(k + 1, array<int, 2> {LLONG_MAX, LLONG_MIN}));
  for (int i = 0; i < n; i++) {
    dp[i][1][0] = dp[i][1][1] = a[i];
    for (int j = 2; j <= min(i + 1, k); j++) {
      for (int _i = i - 1; _i >= max(j - 2, i - maxi); _i--) {
          dp[i][j][0] = min({dp[_i][j - 1][0] * a[i], dp[_i][j - 1][1] * a[i], dp[i][j][0]});
          dp[i][j][1] = max({dp[_i][j - 1][0] * a[i], dp[_i][j - 1][1] * a[i], dp[i][j][1]});
      }
    }
    ans = max(ans, dp[i][k][1]);
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
