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

const int mod = 1e9 + 7;

vector dp(705, vector(705, vector(3, vector<int> (3, -1))));
vector<int> a(705);

int rec(int l, int r, int x, int y) {
  if (l > r) return 1;
  if (dp[l][r][x][y] != -1) return dp[l][r][x][y];

  int res = 0;
  if (a[l] == r) {
    for (int i = 1; i <= 2; i++) {
      if (x != i) res = (res + rec(l + 1, r - 1, i, 0)) % mod;
      if (y != i) res = (res + rec(l + 1, r - 1, 0, i)) % mod;
    }
  }
  else {
    for (int i = 1; i <= 2; i++) {
      if (x != i) res = (res + rec(l + 1, a[l] - 1, i, 0) * rec(a[l] + 1, r, 0, y)) % mod;
      res = (res + rec(l + 1, a[l] - 1, 0, i) * rec(a[l] + 1, r, i, y)) % mod;
    }
  }

  return dp[l][r][x][y] = res;
}

void solve() {
  string s;
  cin >> s;
  vector<int> b;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') b.push_back(i);
    else {
      a[b.back()] = i;
      b.pop_back();
    }
  }
  cout << rec(0, s.size() - 1, 0, 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
