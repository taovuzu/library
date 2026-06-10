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

  int ans = min(k, n - k + 1);
  k--;
  int j = k, l = k;
  while (j > 0 && s[j - 1] == '.') j--;
  while (l < n - 1 && s[l + 1] == '.') l++;
  j++, l++;
  ans = min(ans, max(min(j, n - j + 1), min(l, n - l + 1)));

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
