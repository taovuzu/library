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

int n;
int a[3005][3];

bool check(int i, int j) {
  if (a[i][0] < 0 && a[j][0] < 0) return false;
  if (a[i][0] > 0 && a[j][0] > 0) return false;

  int x = a[i][0], y = a[i][1], z = a[i][2];
  int u = a[j][0], v = a[j][1], w = a[j][2];

  if ((y - v) * (y - v) - 4 * (x - u) * (z - w) < 0) return true;
  return false;
}

bool check1 (int i, int j) {
  if (a[i][0] != a[j][0] || a[i][1] != a[j][1]) return false;
  return a[i][0] > 0 ? a[j][2] < a[i][2] : a[j][2] > a[i][2];
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  vector<set<int>> b(n), c(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][0] == a[j][0] && a[i][1] == a[j][1]) {
        if (a[i][0] > 0) {
          if (a[j][2] > a[i][2]) {
            b[i].insert(a[j][2]);
          }
        }
        else {
          if (a[j][2] < a[i][2]) {
            c[i].insert(a[j][2]);
          }
        }
      }
    }
  }

  pr(b, c);

  vector<int> dp(n + 5);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (check(i, j)) {
        pr(i, j);
        dp[i] = max(dp[i], 1LL + (int)(a[i][0] > 0 ? c[j].size() : b[j].size()));
      }
    }
  }

  pr(dp);

  for (int i = 0; i < n; i++) {
    int ans = 1LL + (a[i][0] > 0 ? b[i].size() : c[i].size()) + dp[i]; 

    for (int j = 0; j < n; j++) {
      if (check1 (i, j)) {
        pr(i, j);
        ans = max(ans, 1LL + (int)(a[j][0] > 0 ? b[j].size() : c[j].size()) + dp[j]);
      }
    }

    cout << ans << " \n"[i == n - 1];
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
