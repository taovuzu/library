// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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

string s;

int check(int x) {
  int tmp = 0;
  while (x) {
    tmp += x % 10;
    x /= 10;
  }

  return tmp;
}

int rec(int idx, int sum, vector<vector<int>> &dp) {
  if (idx == s.size()) {
    return sum == check(sum) ? 0 : 1e9;
  }
  if (dp[idx][sum] != LLONG_MAX) return dp[idx][sum];

  for (int i = 0; i <= 9; i++) {
    if (sum == 0 && i == 0) continue;
    int tmp = (i + '0') != s[idx];
    dp[idx][sum] = min(dp[idx][sum], tmp + rec(idx + 1, sum + i, dp));
  }

  return dp[idx][sum];
}

void solve() {
  cin >> s;

  vector dp(30, vector<int> (300, LLONG_MAX));
  rec(0, 0, dp);

  cout << dp[0][0] << "\n";
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
