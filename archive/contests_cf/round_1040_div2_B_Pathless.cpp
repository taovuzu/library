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
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bool flag = true;
  int sum = accumulate(a.begin(), a.end(), 0LL);
  for (int i = 0; i <= 500; i++) {
    for (int j = 0; j <= 350; j++) {
      if (s == (2 * i + 3 * j + sum)) flag = false;
    }
  }

  if (flag) {
     for (int i = 0; i < n; i++) {
      if (a[i] == 0)  cout << 0 << " ";
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 2)  cout << 2 << " ";
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 1)  cout << 1 << " ";
    }
  }
  else {
   cout << -1;
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
