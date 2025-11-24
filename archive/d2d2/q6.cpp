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

const int MAX = 1e18;

int n;
vector<double> a(1005);
vector dp(1005, vector<double>(1005, -1.0));

double calc(int l, int r) {
  int x = 1, y = 1, cnt = 0;
  while (true) {
    int mini = min(y, r), maxi = max(x, l) - 1;
    cnt += max(0LL, mini - maxi);
    if (x == MAX) break;
    x *= 10;
    y = y * 10 + 9;
  }
  return (1.0 * cnt) / (r - l + 1);
}

double rec(int idx, int k) {
  if (k <= 0) return 1;
  if (idx >= n) return 0;
  if (dp[idx][k] != -1.0) return dp[idx][k];
  dp[idx][k] = a[idx] * rec(idx + 1, k - 1) + (1 - a[idx]) * rec(idx + 1, k);
  return dp[idx][k];
}

void solve() {
  int k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a[i] = calc(l, r);
  }
  cin >> k;
  k = (n * k + 99) / 100;
  cout << setprecision(12) << fixed << rec(0, k);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
