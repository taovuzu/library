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

  bool flag = true;
  set<int> xt;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   xt.insert(x);
  }

  if (xt.size() > 2 || xt.find(0) != xt.end()) {
    flag = false;
  }
  if (*xt.begin() != -1 && xt.size() == 2) {
    flag = false;
  }

  cout << (flag ? "YES" : "NO") << "\n";
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
