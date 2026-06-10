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
  int n, x = 10;
  cin >> n;
  vector<int> ans;
  while ((x + 1) <= n) {
    if (n % (x + 1) == 0) {
      ans.push_back(n / (x + 1));
    }
    x *= 10;
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
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
