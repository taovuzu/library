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
  int n, q;
  string s;
  cin >> n >> q >> s;

  bool flag = false;
  for (auto ch : s) {
    if (ch == 'B') flag = true;
  }

  while (q--) {
    int x, ans = 0, i = 0;
    cin >> x;
    if (!flag) { 
      cout << x << "\n";
      continue;
    }
    while (x) {
      ans++;
      if (s[i] == 'A') x--;
      else x >>= 1;
      i = (i + 1) % n;
    }
    cout << ans << "\n";
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
 