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
  int n, u, alice = 0, bob = 0;
  cin >> n;
  map<int, int> mp;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> u;
    mp[u]++;
  }
  for (auto &[x, y] : mp) {
    alice += (x / 2) * y, bob += (x / 2) * y;
    if (x & 1) a.push_back(y);
  }
  pr(alice, bob);
  pr(a);
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < a.size(); i++) {
    if (i & 1) bob += a[i];
    else alice += a[i];
  }
  cout << alice << " " << bob << "\n";
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
