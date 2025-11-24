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

const int INF = -1e9;

void solve() {
  int n, q, u, v, x, y;
  cin >> n >> q;

  vector<vector<int>> a(n, vector<int> (n, 1)), b(n, vector<int> (n, 0));
  for (int i = 0; i < q; i++) {
    cin >> u >> v >> x >> y;
    u--, v--, x--, y--;
    for (int j = u; j <= x; j++) {
      for (int k = v; k <= y; k++) {
        a[j][k] = INF;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    b[i][0] = a[i][0];
    for (int j = 1; j < n; j++) {
      b[i][j] += (b[i][j - 1] + a[i][j]);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      vector<int> c(n);
      for (int k = 0; k < n; k++) {
        c[k] = b[k][j] - (i > 0 ? b[k][i - 1] : 0);
      }
      int sum = 0;
      for (int k = 0; k < n; k++) {
        sum += c[k];
        ans = max(sum, ans);
        if (sum < 0) sum = 0;
      }
    }
  }

  cout << ans << "\n";
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
