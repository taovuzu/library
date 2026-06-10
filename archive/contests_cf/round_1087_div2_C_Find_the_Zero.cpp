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

int query(int x, int y) {
  cout << "? " << x << " " << y << "\n";
  cout.flush();

  int u;
  cin >> u;

  return u;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= (2 * n - 2); i += 2) {
    int u = query(i, i + 1);
    if (u == 1) {
      cout << "! " << i << "\n";
      cout.flush();
      return;
    }
  }

  if (query(2 * n - 1, 1) || query(2 * n - 1, 2)) {
    cout << "! " << 2 * n - 1 << "\n";
    cout.flush();
  }
  else {
    cout << "! " << 2 * n << "\n";
    cout.flush();
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
