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

const int inf = 1e9;
int n, m, q;
vector<vector<int>> g1(55, vector<int> (55, inf)), dp(55, vector<int> (100100));

bool build_path(int u, int v, int par, vector<int> &path) {
  if (u == v) return true;
  for (int i = 0; i < n; i++) {
    if (g1[u][i] != inf && i!= par) {
      path.push_back(g1[u][i]);
      if (build_path(i, v, u, path)) {
        return true;
      }
      path.pop_back();
    }
  }
  return false;
}

int rec(int idx, int target, vector<int> &path) {
  if (target == 0) return 0;
  if (target < 0 || idx >= path.size()) return inf;
  if (dp[idx][target] != -1) return dp[idx][target];
  return dp[idx][target] = min(rec(idx + 1, target, path), 2 + rec(idx, target - 2 * path[idx], path));
}


void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g1[i][j] = inf;
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g1[u - 1][v - 1] = w;
    g1[v - 1][u - 1] = w;
  }

  cin >> q;
  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    if (u == v ) {
      cout << "No" << "\n";
      continue;
    }
    vector<int> path;
    build_path(u, v, -1, path);
    w -= accumulate(path.begin(), path.end(), 0LL);
    path.pop_back();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= w; j++) {
        dp[i][j] = -1;
      }
    }
    int ans = path.size() + 1 + rec(0, w, path);
    if (ans < inf) {
      cout << "Yes" << " " << ans << "\n";
    }
    else {
      cout << "No" << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    if (t_ > 1) cout << "\n";
    solve();
  }

  return 0;
}
