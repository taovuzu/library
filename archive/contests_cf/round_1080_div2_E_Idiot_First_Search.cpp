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

const int mod = 1e9 + 7;

int n;
array<int, 2> g[300300];
int p[300300], dp[300300];

int dfs(int u) {

  if (g[u][0]) p[u] += dfs(g[u][0]) + 2;
  if (g[u][1]) p[u] += dfs(g[u][1]) + 2;

  return p[u] % mod;
}

void dfs1(int u, int sum) {
  dp[u] = (p[u] + sum) % mod;

  if (g[u][0]) dfs1(g[u][0], (sum + p[u] + 1) % mod);
  if (g[u][1]) dfs1(g[u][1], (sum + p[u] + 1) % mod);
}

void solve() {
  g[0][0] = 1;
  g[0][1] = 0;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    g[i][0] = l;
    g[i][1] = r;

    p[i] = 0;
  }

  dfs(1);
  dfs1(0, 0);

  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " \n"[i == n];
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
