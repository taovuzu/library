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
  vector a(n, array<int, 3>());
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i + 1;
  }
  sort(a.begin(), a.end());

  vector<int> ans;
  int last = 0;
  for (int i = 0; i < n; i++) {
    while (i + 1 < n && a[i + 1][0] == a[i][0]) i++;
    if (i < n && a[i][1] > last) ans.push_back(a[i][2]), last = a[i][1];
  }

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
