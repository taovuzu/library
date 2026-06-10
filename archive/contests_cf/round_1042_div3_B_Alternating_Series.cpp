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
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (!(n & 1)) {
        cout << 2;
      }
      else {
        cout << -1;
      }
      break;
    }
    if (i & 1) {
      cout << 3 << " ";
    }
    else {
      cout << -1 << " ";
    }
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
