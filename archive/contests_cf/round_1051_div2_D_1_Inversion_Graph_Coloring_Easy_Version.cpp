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

const int mod = 1e9 + 7;
int n;
vector<int> a(330);
vector dp(330, vector(330, vector<int> (330)));

int rec(int idx, int val1, int val2) {
  if (idx >= n) return 1;
  if (dp[idx][val1][val2] != -1) return dp[idx][val1][val2];
  int ans = rec(idx + 1, val1, val2) % mod;
  if (a[idx] >= val1 && a[idx] >= val2) ans = (ans + max(rec(idx + 1, a[idx], val2), rec(idx + 1, val1, a[idx]))) % mod;
  else if (a[idx] >= val1) ans = (ans + rec(idx + 1, a[idx], val2)) % mod;
  else if (a[idx] >= val2) ans = (ans + rec(idx + 1, val1, a[idx])) % mod;
  pr(idx, val1, val2, ans);
  return dp[idx][val1][val2] = ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << rec(0, 0, 0) << "\n";
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
