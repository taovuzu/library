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
  cin >> n >> k;
  if (k == n * n - 1) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES"<< "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (k-- > 0) cout << "U";
      else if (i == n - 1) {
        if (j == n - 1) cout << "L";
        else cout << "R";
      }
      else {
        cout << "D";
      }
    }
    cout << "\n";
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
