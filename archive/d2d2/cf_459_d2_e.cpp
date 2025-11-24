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
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m); // from, to, cost
  vector<int> dp(n + 1), ndp(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u - 1, v - 1, w};
  }
  sort(edges.begin(), edges.end(), [](auto &x, auto &y){ return x[2] < y[2]; });
  int ans = 0;
  for (int i = 0; i < m;) {
    int j = i;
    while (j < m && edges[j][2] == edges[i][2]) {
      int u = edges[j][0], v = edges[j][1];
      ndp[v] = max(ndp[v], dp[u] + 1);
      j++;
    }
    j = i;
    while (j < m && edges[j][2] == edges[i][2]) {
      int v = edges[j][1];
      dp[v] = ndp[v];
      ans = max(ans, dp[v]);
      j++;
    }
    i = j;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
