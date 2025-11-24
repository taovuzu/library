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

const int mod = 555555555;
int n, mudCount;
int dp[560][560][2][3];

int solve(int idx, int mud, int flag, int prev) {
  if (idx >= n - 1) {
    return mud == 0 && (flag || (prev == 2));
  }
  if (dp[idx][mud][flag][prev] != -1) return dp[idx][mud][flag][prev];

  dp[idx][mud][flag][prev] = solve(idx + 1, mud, flag, (prev + 1) % 3);
  if (idx && mud) dp[idx][mud][flag][prev] += solve(idx + 1, mud - 1, flag || (prev == 0), 0);

  return dp[idx][mud][flag][prev] % mod;
}

void solve() {
  cin >> n >> mudCount;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, mudCount, 0, 0) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
