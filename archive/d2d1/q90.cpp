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

int val[26], sum[100100], ans, n;
vector<int> pos[26];
string s;

void solve() {
  for (int i = 0; i < 26; i++) {
    cin >> val[i];
  }
  cin >> s;

  n = s.size();
  for (int i = 0; i < n; i++) {
    sum[i] = val[s[i] - 'a'] + (i ? sum[i - 1] : 0);
    pos[s[i] - 'a'].push_back(i);
  }

  for (int i = 0; i < 26; i++) {
    map<int, int> mp;
    for (int j = 0; j < pos[i].size(); j++) {
      int x = pos[i][j];
      if(x) ans += mp[sum[x - 1]];
      mp[sum[x]]++;
    }
  }

  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
