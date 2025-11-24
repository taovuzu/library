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

int n;
string needle, hay;

void lpsFind(string &s, vector<int> &a) {
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (s[i] != s[k] && k > 0) k = a[k - 1];
    if (s[i] == s[k]) k++;
    a[i] = k;
  }
}

void solve() {
  vector<int> ans, lps(n);
  lpsFind(needle, lps);
  int k = 0;
  for (int i = 0; i < hay.size(); i++) {
    while (k > 0 && (hay[i] != needle[k] || k == n)) k = lps[k - 1];
    if (hay[i] == needle[k]) k++;
    if (k == n) ans.push_back(i - n + 1);
  }
  for (int i = 0; i < ans.size(); i++)  {
    cout << ans[i] << "\n";
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n >> needle >> hay) {
    solve();
  }

  return 0;
}
