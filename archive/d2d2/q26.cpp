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

void solve() {
  int w, b;
  cin >> w >> b;
  vector dp(w + 1, vector<double> (b + 1, 0.0));
  for (int i = 1; i <= w; i++) {
    dp[i][0] = 1.0;
    for (int j = 1; j <= b; j++) {
      dp[i][j] = (i * 1.0) / (i + j);
      double x = ((j * 1.0) / (i + j)) * ((j - 1.0) / (i + j - 1)), y = 0;
      if (j - 2 >= 0) y += (i * 1.0) / (i + j - 2) * dp[i - 1][j - 2];
      if (j - 3 >= 0) y += (j - 2.0) / (i + j - 2) * dp[i][j - 3];
      dp[i][j] += y * x;
    }
  }
  cout << setprecision(12) << fixed << dp[w][b];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
