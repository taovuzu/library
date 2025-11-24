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

string s;
int a[2][2], ans[2];

void solve() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    ++a[i & 1][s[i] - 'a'];
    ans[0] += a[(i ^ 1) & 1][s[i] - 'a'];
    ans[1] += a[i & 1][s[i] - 'a'];
  }
  cout << ans[0] << " " << ans[1] << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
