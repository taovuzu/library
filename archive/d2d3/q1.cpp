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
  int n;
  cin >> n;

  map<int, int> mp;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!mp.count(a[i])) {
      mp[a[i]] = mp.size();
    }
    a[i] = mp[a[i]];
  }

  int ans = 1;
  vector dp(n, vector<int> (4005, 1));
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      dp[i][a[j]] = max(1 + dp[j][a[i]], dp[i][a[j]]);
      ans = max(ans, dp[i][a[j]]);
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
