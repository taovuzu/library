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
  int x, l, n;
  cin >> x >> l >> n;

  int ans = l < x ? (x - l) : 0;
  if (x & 1) {
    for (int bit = 64 - __builtin_clzll(max(l, x)); bit <= 64 - __builtin_clzll(n); bit++) {
      int y = ((x - 1) >> 1) + (1LL << (bit - 1));
      if (y >= max(l, x) && y <= min((1LL << bit), n)) ans++;
    }
  }

  int p = ans, q = n - l + 1;
  int g = __gcd(p, q);
  cout << p / g << "/"  << q / g << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    cout << "Case " << t_ << ": ";
    solve();
  }

  return 0;
}
