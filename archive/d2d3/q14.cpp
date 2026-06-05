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

int ask(int i, int x) {
  cout << "? " << i << " " << x << endl;

  int y;
  cin >> y;

  return y;
}

void solve() {
  int n;
  cin >> n;

  int ans = 0;
  vector<int> a(n - 1);
  iota(a.begin(), a.end(), 1);

  int len = 63 - __builtin_clzll(n);

  for (int i = 0; i < len; i++) {
    int mask = 1LL << i;
    int sum = 0;

    vector<int> b, c;
    for (int i = 0; i < a.size(); i++) {
      if (ask(a[i], mask)) {
        sum++;
        b.push_back(a[i]);
      }
      else {
        c.push_back(a[i]);
      }
    }

    if (sum != total) {
      ans |= mask;
    }
    else {
      
    }

  }

  cout << "! " << ans << endl;
}

int32_t main() {

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
