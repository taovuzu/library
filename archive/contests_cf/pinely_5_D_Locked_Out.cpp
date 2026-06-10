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

int rec(int idx, int last, vector<int> &a, vector<array<int, 2>> &dp) {
  if (idx >= a.size()) return 0;
  if (dp[idx][last] != -1) return dp[idx][last];

  dp[idx][last] = a[idx] + rec(idx + 1, 1, a, dp);
  if (last) dp[idx][last] = min(dp[idx][last], rec(idx + 1, 0, a, dp));

  return dp[idx][last];
}

void solve() {
  int n;
  cin >> n;
  
  vector<int> a(n), b(n + 2), c(n + 2), b1(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    c[a[i]]--;
    if (c[a[i] + 1]) b[a[i]]++;
    else if (b[a[i] - 1]) b1[a[i]]++;
    if (!c[a[i]] && !c[a[i] + 1]) {
      int x = a[i] - 1;
      vector<int> d{b1[a[i]]};
      while (x && b[x]) {
        d.push_back(b[x]);
        x--;
      }
      pr(a[i], d);
      vector<array<int, 2>> dp(d.size() + 2, {-1, -1});
      ans += rec(0, 1, d, dp);
    }
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
