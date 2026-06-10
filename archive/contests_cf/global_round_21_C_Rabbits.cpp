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

int n;
string s;

vector<int> dp(200200);

bool rec(int idx) {
  if (idx >= n - 1) return true;
  if (dp[idx] != -1) return dp[idx];
  if (s[idx] != '0') return rec(idx + 1);
  bool ans = false;
  if ((idx == 0) || (idx == n - 1) || (idx >= 1 && s[idx - 1] == '0') ||(idx <= n - 2 && s[idx + 1] == '0')) ans |= rec(idx + 1);
  if ((idx <= n - 3 && s[idx + 2] == '0')) ans |= rec(idx + 3);
  return dp[idx] = ans;
}

void solve() {
  cin >> n >> s;
  for (int i = 0; i <= n + 50; i++) dp[i] = -1;
  bool flag = rec(0);
  cout << (flag ? "YES" : "NO") << "\n";
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
