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

const int inf = 1e16;
int n, m;

array<int, 3> rec(int i, int j, vector<vector<int>> &a, vector<vector<array<int, 3>>> &dp) {
  if (i >= n || j >= m) return {-inf, -1, -1};
  if (i == n - 1 && j == m - 1) return {a[i][j], i , j};
  if (dp[i][j][0] !=  LLONG_MIN) return dp[i][j];

  auto r = rec(i, j + 1, a, dp);
  auto d = rec(i + 1, j, a, dp);

  if (r[0] < d[0]) {
    dp[i][j] = d;
  }
  else if (r[0] > d[0]) {
    dp[i][j] = r;
  }
  else {
    if (a[r[1]][r[2]] < a[d[1]][d[2]]) {
      dp[i][j] = d;
    }
    else {
      dp[i][j] = r;
    }
  }

  dp[i][j][0] += a[i][j];

  if (a[dp[i][j][1]][dp[i][j][2]] < a[i][j]) {
    dp[i][j][1] = i;
    dp[i][j][2] = j;
  }

  return dp[i][j];
}

int rec1(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp1) {
  if (i >= n || j >= m) return -inf;
  if (i == n - 1 && j == m - 1) return a[i][j];
  if (dp1[i][j] !=  LLONG_MIN) return dp1[i][j];

  auto r = rec1(i, j + 1, a, dp1);
  auto d = rec1(i + 1, j, a, dp1);

  return dp1[i][j] = max(r, d) + a[i][j];
}

void solve() {
  cin >> n >> m;

  vector a(n, vector<int> (m)), dp1(n + 5, vector<int> (m + 1, LLONG_MIN)); 
  vector dp(n + 5, vector<array<int, 3>> (m + 5, {LLONG_MIN, -1, -1}));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  rec(0, 0, a, dp);
  a[dp[0][0][1]][dp[0][0][2]] *= -1;
  rec1(0, 0, a, dp1);

  cout << dp1[0][0] << "\n";
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
