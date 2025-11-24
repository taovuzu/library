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

int n, l, c;
vector<int> a(1001);
vector<array<int, 2>> dp(1001);

array<int, 2> rec(int i) {
  if (i >= n) return {0, 0};
  array<int, 2> tmp = {LLONG_MAX, LLONG_MAX};
  if (dp[i] != tmp) return dp[i];
  int j = i, sum = a[i];
  while (j < n && sum <= l) {
    int x = (l - sum > 10) ? (l - sum - 10) * (l - sum - 10) : (l - sum >= 1 ? -c : 0);
    tmp = rec(j + 1);
    tmp[0]++, tmp[1] += (x);
    if (dp[i][0] > tmp[0] || (dp[i][0] == tmp[0] && dp[i][1] > tmp[1])) dp[i] = tmp;
    j++;
    if (j < n) sum += a[j];
  }
  return dp[i];
}

void solve() {
  cin >> l >> c;
  for (int i = 0; i < n; i++) {
    dp[i] = {LLONG_MAX, LLONG_MAX};
    cin >> a[i];
  }
  rec(0);
  cout << "Minimum number of lectures: " << dp[0][0] << "\n" << "Total dissatisfaction index: " << dp[0][1] << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 0;
  while (cin >> n && n) {
    if (tt) cout << "\n";
    cout << "Case " << ++tt << ":" << "\n";
    solve();
  }

  return 0;
}
