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

double dp[105][105][105];
bool vis[105][105][105];

double rec(int r, int s, int p) {
  if (r && s == 0 && p == 0) return 1;
  if (r < 0 || s < 0 || p < 0 || (r*s + s*p + p*r) == 0) return 0;
  if (vis[r][s][p]) return dp[r][s][p];
  vis[r][s][p] = true;
  return dp[r][s][p] = 1.0 * r * s / (r*s + s*p + p*r) * rec(r, s - 1, p) + 1.0 * r * p / (r*s + s*p + p*r) * rec(r - 1, s, p) + 1.0 * s * p / (r*s + s*p + p*r) * rec(r, s, p - 1);
}

void solve() {
  int r, s, p;
  cin >> r >> s >> p;
  double x = rec(r, s, p);
  memset(vis, 0, sizeof(vis));
  double y = rec(s, p, r);
  cout << setprecision(12) << fixed << x << " " << y << " " << (1.0 - x - y);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
