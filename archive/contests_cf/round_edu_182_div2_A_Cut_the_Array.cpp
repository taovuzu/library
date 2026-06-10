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
  int n;
  cin >> n;
  vector<int> a(n), pre(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) pre[i] = a[i] + pre[i - 1];
    else pre[i] = a[i];
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int x = pre[i] % 3, y = (pre[j] - pre[i]) % 3, z = (pre[n - 1] - pre[j]) % 3;
      if ((x != y && y != z && x != z) || (x == y && y == z)) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "0 0" << "\n";
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
