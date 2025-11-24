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
  vector a(n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> b(n), ans(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }
  for (int k = n - 1; k >= 0; k--) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = min(a[i][j], a[i][b[k]] + a[b[k]][j]);
      }
    }
    for (int i = k; i < n; i++) {
      for (int j = k; j < n; j++) {
        ans[k] += a[b[i]][b[j]];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
