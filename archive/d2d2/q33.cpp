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

int n;
vector<int> a(200200);
vector<array<int, 2>> dp(200200, {LLONG_MIN, LLONG_MIN}), vis(200200, {0, 0});

int rec(int x, int flag) {
  if (x <= 0 || x > n) return 0;
  if (vis[x][flag]) return -1;
  if (dp[x][flag] != LLONG_MIN) return dp[x][flag];
  vis[x][flag] = 1;
  if (flag) dp[x][flag] = rec(x - a[x], 0);
  else dp[x][flag] = rec(x + a[x], 1);
  vis[x][flag] = 0;
  if (dp[x][flag] == -1) return -1;
  return dp[x][flag] += a[x];
}

void solve() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  vis[1][0] = 1;
  for (int i = 1; i < n; i++) {
    a[1] = i;
    cout << (rec(1 + a[1], 1) + (rec(1 + a[1], 1) == -1 ? 0 : i)) << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
