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

int n, x, k;
vector<int> a(60), g[60];
vector dp(60, vector<int> (2005, -1));
string s;

int rec(int u, int left) {
  if (left <= 0) return 0;
  if (dp[u][left] != -1) return dp[u][left];
  int ans = inf;
  for (auto v : g[u]) {
    ans = min(ans, abs(v - u) + rec(v, left - a[v]));
  }
  return dp[u][left] = ans;
}

void solve() {
  cin >> n >> x >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[j] != s[i] && a[i] < a[j]) {
        g[i].push_back(j);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, abs(i - (x - 1)) + rec(i, k - a[i]));
  }
  cout << (ans == inf ? -1 : ans) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
