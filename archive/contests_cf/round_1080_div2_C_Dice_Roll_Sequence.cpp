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

const int inf = 1e9;

int n;
int a[300300];
int dp[300300][8];

int rec(int idx, int last) {
  if (idx == n) return 0;
  if (dp[idx][last] != inf) return dp[idx][last];

  int ans = inf;
  if (a[idx] != 7 - last && a[idx] != last) {
    ans = rec(idx + 1, a[idx]);
  }

  for (int i = 1; i <= 6; i++) {
    if (i != 7 - last && i != last) {
      ans = min(ans, 1 + rec(idx + 1, i));
    }
  }

  return dp[idx][last] = ans;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 8; j++) {
      dp[i][j] = inf;
    }
  }

  cout << rec(0, 7) << "\n";
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
