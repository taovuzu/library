// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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

int unSetKth(int x, int k) {
  return x & ~(1LL << k);
}

void solve() {
  int s, m;
  cin >> s >> m;

  int g = 1LL << __builtin_ctzll(m);
  if (s % g) {
    cout << -1 << "\n";
    return;
  }

  int curr = s, n = m;
  int ans = 0;

  pr(s, m);
  while (curr) {
    pr(n, curr, ans);
    ans += curr / n;
    curr = curr % n;

    int tmp = 0;
    for (int i = 30; i >= 0; i--) {
      if ((m >> i) & 1) {
        if (curr >= (tmp | (1LL << i))) {
          tmp |= (1LL << i);
        }
      }
    }

    n = tmp;
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
