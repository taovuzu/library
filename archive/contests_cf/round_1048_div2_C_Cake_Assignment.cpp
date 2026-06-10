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
  int k, x, u, v;
  cin >> k >> x;
  u = x , v = ((1LL << (k + 1)) - x);
  vector<int> ans;
  while (u != v) {
    if (u < v) {
      ans.push_back(1);
      v -= u;
      u <<= 1;
    }
    else {
      ans.push_back(2);
      u -= v;
      v <<= 1;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
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
