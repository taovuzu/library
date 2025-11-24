// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve() {
  int n, q, u, v, x;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  cin >> q;
  while (q--) {
    cin >> u >> v >> x;
    a[u - 1][v - 1] = a[v - 1][u - 1] = min(a[u - 1][v - 1], x);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = min(a[i][u - 1] + a[u - 1][j], a[i][j]);
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = min(a[i][v - 1] + a[v - 1][j], a[i][j]);
        if (i < j) sum += a[i][j];
      }
    }

    cout << sum << " ";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
