// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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
string s;
set<string> xt;
int dp[10010][3];

bool solve(int idx, int last) {
  if (idx >= n ) return true;
  if (idx == n - 1) return false;
  string s1 = s.substr(idx - last, last);

  if (dp[idx][last] != -1) return dp[idx][last];

  bool check1 = false, check2 = false;
  if (s1 != s.substr(idx, 2)) check1 = solve(idx + 2, 2);
  if (s1 != s.substr(idx, 3)) check2 = solve(idx + 3, 3);

  if (check1) xt.insert(s.substr(idx, 2));
  if (check2) xt.insert(s.substr(idx, 3));

  return dp[idx][last] = (check1 || check2);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  n = s.size();
  memset(dp, -1, sizeof(dp));

  for (int i = 5; i < n; i++) {
    solve(i, 0);
  }

  cout << xt.size() << "\n";

  vector<string> ans;
  for (auto it : xt) {
    ans.push_back(it);
  }

  sort(ans.begin(), ans.end());
  for (auto it : ans) {
    cout << it << "\n";
  }

  return 0;
}
