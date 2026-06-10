// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
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
  string ans(n, '+');
  int i = 0, j = n - 1, x = 0;
  for (int i_ = 0; i_ < k; i_++) {
    if (s[i_] == '0') ans[i] = '-', i++;
    else if (s[i_] == '1') ans[j] = '-', j--;
    else x++;
  }
  if (j - i + 1 == x) {
    for (int i_ = 0; i_ < n; i_++) ans[i_] = '-';
  }
  else {
    for (int i_ = i; i_ < i + x; i_++) ans[i_] = '?';
    for (int i_ = j; i_ > j - x; i_--) ans[i_] = '?';
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
