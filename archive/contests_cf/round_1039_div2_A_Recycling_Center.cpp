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
  int n, c;
  cin >> n >> c;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<bool> vis(n, false);
  while (c) {
    int j = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] <= c && vis[i] == false) {
        if (j < 0) j = i;
        else if (a[i] > a[j]) {
          j = i;
        }
      }
    }
    if (j >= 0) vis[j] = true;
    c /= 2;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == false) ans++;
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
