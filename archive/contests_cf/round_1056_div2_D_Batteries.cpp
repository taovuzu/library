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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int a, int b) { return a + rng() % (b - a + 1); }


void solve() {
  int n;
  set<array<int, 2>> xt;
  cin >> n;
  while (true) {
    int z, x = rnd(1, n), y = rnd(1, n);
    if (x == y || xt.count({x, y})) continue;
    xt.insert({x, y});
    cout << x << " " << y << endl;
    cin >> z;
    if (z == -1) exit(0);
    if (z == 1) return;
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
