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

int n;
int a[10010], dp[10010], dp1[10010];

void lis() {
  vector<int> b;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    if (it == b.end()) {
      b.push_back(a[i]);
    }
    else {
      *it = a[i];
    }
    dp[i] = b.size();
  }
}

void lds() {
  vector<int> b;
  for (int i = n - 1; i >= 0; i--) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    if (it == b.end()) {
      b.push_back(a[i]);
    }
    else {
      *it = a[i];
    }
    dp1[i] = b.size();
  }
}

void solve() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    lis();
    lds();

    int ans = 1;
    for (int i = 0; i < n; i++) {
      ans = max(ans, min(dp[i], dp1[i]) * 2 - 1);
    }

    cout << ans << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
