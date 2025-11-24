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

const int mod = 1e9 + 7;

void lpsFind(string &s, vector<int> &lps) {
  for (int i = 1, k = 0; i < s.size(); i++) {
    while (k > 0 && (s[i] != s[k])) k = lps[k - 1];
    if (s[i] == s[k]) k++;
    lps[i] = k;
  }
}

vector<int> kmp(string &s, string &w, vector<int> &lps) {
  vector<int> ans;
  for (int i = 0, k = 0; i < s.size(); i++) {
    while (k > 0 && (k == w.size() || s[i] != w[k])) k = lps[k - 1];
    if (s[i] == w[k]) k++;
    if (k == w.size()) ans.push_back(i - w.size() + 1);
  }
  return ans;
}


void solve() {
  int n, m;
  string p;
  cin >> n >> m >> p;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  string s = "";
  int i = 0, j = 0, ans = 1;
  while (i < m) {
    while (s.size() < a[i]) s += "?", ans = (ans * 26) % mod;
    s += p.substr(s.size() - a[i]);
    i++;
  }
  while (s.size() < n) s += "?", ans = (ans * 26) % mod;

  vector<int> lps(p.size());
  lpsFind(p, lps);
  vector<int> b = kmp(s, p, lps);
  i = 0;
  while (i < m) {
    while (j < b.size() && b[j] < a[i]) j++;
    if (j == b.size() || b[j] > a[i]) {
      cout << 0 << "\n";
      return;
    }
    i++;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
