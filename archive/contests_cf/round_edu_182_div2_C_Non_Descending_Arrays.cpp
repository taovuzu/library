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

const int mod = 998244353;
int n;
vector<int> a(550), b(550);
vector<array<int, 2>> dp(550);

int rec(int idx, int last) {
  if (idx > n) return 1;
  if (dp[idx][last] != -1) return dp[idx][last];
  int lastx = last ? b[idx - 1] : a[idx - 1];
  int lasty = last ? a[idx - 1] : b[idx - 1];
  dp[idx][last] = 0;
  if (a[idx] >= lastx && b[idx] >= lasty) dp[idx][last] += rec(idx + 1, 0);
  if (a[idx] >= lasty && b[idx] >= lastx) dp[idx][last] += rec(idx + 1, 1);
  return dp[idx][last] % mod;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i] = {-1, -1};
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  cout << rec(1, 0) << "\n";
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
