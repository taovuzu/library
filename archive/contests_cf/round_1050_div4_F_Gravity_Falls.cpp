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

  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    a[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
  }

  int len = 0;
  vector<int> ans;

  while (true) {
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (a[i].size() > len) {
        vector<int> x(a[i].begin() + len, a[i].end());
        if (b.empty() || x < b) {
          b = x;
        }
      }
    }
    if (b.empty()) break;
    ans.insert(ans.end(), b.begin(), b.end());
    len = ans.size();
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    pr(t_);
    solve();
  }

  return 0;
}

