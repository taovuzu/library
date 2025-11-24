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

string rec(string s) {
  if (s.size() & 1)  return s;
  string s1 = rec(s.substr(0, s.size() / 2));
  string s2 = rec(s.substr(s.size() / 2));
  if (s1 < s2) return s1 + s2;
  return s2 + s1;
}

void solve() {
  string s, s1;
  cin >> s >> s1;
  s = rec(s), s1 = rec(s1);
  cout << (s == s1 ? "YES" : "NO") << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
