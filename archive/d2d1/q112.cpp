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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  set<array<int, 3>> xt;
  xt.insert({accumulate(a.begin(), a.end(), 0LL), 0LL, n - 1});
  while (k--) {
    auto x = *prev(xt.end());
    xt.erase(prev(xt.end()));
    cout << x[0] << " ";
    if (x[1] != x[2]) {
      xt.insert({x[0] - a[x[1]], x[1] + 1, x[2]});
      xt.insert({x[0] - a[x[2]], x[1], x[2] - 1});
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
