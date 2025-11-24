// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
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

int n, m;

void solve() {
  vector<int> a(m), dp(n + 5);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < m; j++) {
      if (i - a[j] >= 0) {
        dp[i] |= !dp[i - a[j]];
      }
    }
  }

  cout << (dp[n] ? "Stan wins" : "Ollie wins") << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n >> m) {
    solve();
  }

  return 0;
}
