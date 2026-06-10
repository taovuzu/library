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
  string s;
  cin >> n >> k >> s;
  vector<int> a(n, -1);
  int len = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') len++;
    else len = 0;
    if (len >= k) {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
  int last = n, i = 0; 
  while (i < n) {
    while (i < n && s[i] != '0') i++;
    if (i < n) {
      a[i] = last;
      last--;
      i++;
    }
  }
  for (i = 0; i < n; i++) {
    if (a[i] == -1) {
      a[i] = last;
      last--;
    }
    cout << a[i] << " \n"[i == n - 1];
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
