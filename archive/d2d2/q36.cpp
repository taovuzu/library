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
  int n, k, p, x, z = 0, u, v;
  cin >> n >> k >> p;
  if (n & 1 && k) z = n, n--, k--;
  while (p--) {
    cin >> x;
    u = (n - x + 2) >> 1;
    v = ((n - x + 1) >> 1) + (n >> 1);
    pr(u, v, x, z, k);
    if ((x == z) || (k && (k >= ((x & 1) ? v : u)))) {
      cout << "X";
    }
    else cout << ".";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
