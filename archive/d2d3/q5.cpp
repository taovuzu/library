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

const int inf = 5e18;

void solve() {
  int n, m, x;
  cin >> n >> m >> x;

  vector<array<int, 3>> a(n); // {monitor, price, problems}
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> a[i][1] >> a[i][0] >> sz;
    for (int j = 0; j < sz; j++) {
      int y;
      cin >> y;
      a[i][2] |= (1 << (y - 1));
    }
  }

  sort(a.begin(), a.end());

  vector<int> dp(1 << m, inf);
  dp[0] = 0;
  int ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = (1 << m) - 1; j >= 0; j--) {
      dp[j | a[i][2]] = min(dp[j | a[i][2]], dp[j] + a[i][1]);
    }
    ans = min(ans, x * a[i][0] + dp[(1 << m) - 1]);
  }

  ans = ans >= inf ? -1 : ans;
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
