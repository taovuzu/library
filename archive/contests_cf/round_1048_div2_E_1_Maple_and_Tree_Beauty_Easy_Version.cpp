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

int n, z;

int dfs(int node, int depth, vector<int> &level, vector<vector<int>> &g) {
  level[depth]++;
  int ans = LLONG_MAX;
  for (auto u : g[node]) {
    ans = min(dfs(u, depth + 1, level, g), ans);
  }
  return ans == LLONG_MAX ? depth : ans;
}

int rec(int depth, int k, int min_depth, vector<int> &level, vector<int> &pre, vector<vector<int>> &dp) {
  pr(depth, k);
  if (depth > min_depth) return 0;
  if (dp[depth][k] != -1) return dp[depth][k];
  int ans = 0, w = (n - z) - (pre[depth - 1] - (z - k));
  pr(w);
  if (k >= level[depth]) {
    ans = max(ans, 1 + rec(depth + 1, k - level[depth], min_depth, level, pre, dp));
  }
  if (w >= level[depth]) {
    ans = max(ans, 1 + rec(depth + 1, k, min_depth, level, pre, dp));
  }
  return dp[depth][k] = ans;
}

void solve() {
  int k;
  cin >> n >> k;
  vector<int> level(n + 1), pre;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  z = k;
  pr(g, n, k, z);
  int min_depth = dfs(1, 1, level, g);
  pre = level;
  for (int i = 2; i <= n; i++) pre[i] += pre[i - 1];
  vector<vector<int>> dp(min_depth + 1, vector<int> (k + 1, -1));
  pr(min_depth, level, pre);
  cout << rec(1, k, min_depth, level, pre, dp) << "\n";
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
