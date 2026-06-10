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
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i += 2) {
    if (a[i] < a[i - 1]) {
      ans += (a[i - 1] - a[i]);
      a[i - 1] = a[i];
    }
    if (i + 1 < n && a[i] < a[i + 1]) {
      ans += (a[i + 1] - a[i]);
      a[i + 1] = a[i];
    }
    if (i + 1 < n) {
      if (a[i - 1] + a[i + 1] > a[i]) {
        int diff = a[i - 1] + a[i + 1] - a[i];
        ans += diff;
        int mini = min(diff, a[i + 1]);
        a[i + 1] -= mini;
        diff -= mini;
        a[i - 1] -= diff;
      }
    }
  }
  cout << ans << "\n";
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
