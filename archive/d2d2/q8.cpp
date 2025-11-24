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

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> lps(n);
  for (int k = 0, i = 1; i < n; i++) {
    while (k > 0 && (s[i] != s[k])) k = lps[k - 1];
    if (s[i] == s[k]) k++;
    lps[i] = k;
    
    if (k == 0 || ((i + 1) % (i + 1 - k))) continue;
    cout << i + 1 << " " << (i + 1) / (i + 1 - k) << "\n";
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    cout << "Test case #" << t_ << "\n";
    solve();
  }

  return 0;
}
