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

int n;
vector<int> g[100100];
vector<array<int, 2>> dp(100100, {LLONG_MAX, LLONG_MAX});

int dfs(int node, int par, bool take) {
  if (dp[node][take] != LLONG_MAX) return dp[node][take];
  int ans = 0;
  for (auto u : g[node]) {
    if (u == par) continue;
    if (take) ans += min(1 + dfs(u, node, take), dfs(u, node, false));
    else ans += 1 + dfs(u, node, true);
  }
  return dp[node][take] = ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  cout << min(1 + dfs(0, -1, true), dfs(0, -1, false));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
