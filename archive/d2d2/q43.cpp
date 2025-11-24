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
string s;
vector<vector<int>> dp(105, vector<int> (105));
map<char, char> mp{{'(', ')'}, {'[', ']'}, {')', '('}, {']', '['}};

int solve(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;
  if (dp[l][r] != inf) return dp[l][r];
  if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']'))  dp[l][r] = min(dp[l][r], solve(l + 1, r - 1));
  for (int i = l; i < r; i++) {
    dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r));
  }
  return dp[l][r];
}

string build(int l, int r) {
  string ans = "";
  if (l > r) return ans;
  if (l == r) {
    if (s[l] == ')' || s[l] == ']') return ans + mp[s[l]] + s[l];
    return ans + s[l] + mp[s[l]];
  }
  if (((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']')) && dp[l][r] == solve(l + 1, r - 1)) return ans + s[l] + build(l + 1, r - 1) + s[r];
  for (int i = l; i < r; i++) {
    if (dp[l][r] == solve(l, i) + solve(i + 1, r)) {
      return ans + build(l, i) + build(i + 1, r);
    }
  }
  return ans;
}

void solve() {
  getline(cin, s);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = inf;
    }
  }
  solve(0, n - 1);
  cout << build(0, n - 1) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int tt;
  getline(cin, s);
  tt = stoi(s);
  for (int t_ = 1; t_ <= tt; t_++) {
    getline(cin, s);
    if (t_ != 1) cout << "\n";
    solve();
  }


  return 0;
}
