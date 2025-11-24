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

void lpsFind(string &s, vector<int> &a) {
  int k = 0;
  for (int i = 1; i < s.size(); i++) {
    while (k > 0 && s[i] != s[k]) k = a[k - 1];
    if (s[i] == s[k]) k++;
    a[i] = k;
  }
}

bool kmp(string &s, string &s1) {
  vector<int> lps(s.size());
  lpsFind(s, lps);
  int k = 0;
  for (int i = 0; i < s1.size(); i++) {
    while (k > 0 && (s1[i] != s[k])) k = lps[k - 1];
    if (s1[i] == s[k]) k++;
    if (k == s.size()) return true;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  string s = "", s1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) s += "G";
    else if (a[i] > a[i + 1]) s += "L";
    else s += "E";
  }
  cin >> s1;

  cout << (kmp(s1, s) ? "YES" : "NO") << "\n";

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
