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
  int curr = n - 1, x, len = 0;
  vector<int> a(n + 1, -1);
  while (curr > 0) {
    cout << "throw " << curr << endl;
    cout.flush();
    cin >> x;
    if (x == len + 1) {
      a[curr] = 2;
    }
    else {
      a[curr] = 1;
    }
    cout << "swap " << curr << endl;
    cout.flush();
    cout << "throw " << curr << endl;
    cout.flush();
    cin >> x;
    if (x == len + 1) {
      a[curr + 1] = 2;
    }
    else {
      a[curr + 1] = 1;
    }
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
