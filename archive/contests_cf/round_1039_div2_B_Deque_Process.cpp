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

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bool flag = true;
  string s = "";
  int l = 0, r = n - 1;
  for (int i = 0; i < n; i++) {
    if (flag) {
      if (a[l] < a[r]) {
        s += 'L';
        l++;
      }
      else {
        s += 'R';
        r--;
      }
      flag = false;
    }
    else {
      if (a[l] > a[r]) {
        s += 'L';
        l++;
      }
      else {
        s += 'R';
        r--;
      }
      flag = true;
    }
  }
  cout << s << "\n";
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
