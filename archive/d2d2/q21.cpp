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
  int n, m;
  cin >> n >> m;
  if (((m + 1) / 2 - 1 > n) || (n > m + 1)) {
    cout << -1;
    return;
  }
  string ans = "";
  if (n > m) {
    while (m) {
      ans += "01";
      m--, n--;
    }
    ans += "0";
  }
  else {
    while (n) {
      if (m > n) ans += "110", n--, m -= 2;
      else ans += "10", n--, m--;
    }
    while (m > 0) ans += "1", m--;
  }
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
