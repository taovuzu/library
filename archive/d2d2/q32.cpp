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

string s, t;

int lps() {
  vector<int> a(t.size());
  for (int i = 1, j = 0; i < t.size(); i++) {
    while (j > 0 && t[j] != t[i]) j = a[j - 1];
    if (t[i] == t[j]) j++;
    a[i] = j;
  }
  return a[t.size() - 1];
}

void solve() {
  cin >> s >> t;
  array<int, 2> a{0, 0};
  for (auto x : s) {
    a[x - '0']++;
  }
  string ans = "";
  int k = lps(), i = 0;
  while (a[0] && a[1]) {
    ans += t[i];
    if (t[i] == '0') a[0]--;
    else a[1]--;
    if (++i == t.size()) i = k;
  }
  while (a[0]) ans += '0', a[0]--;
  while (a[1]) ans += '1', a[1]--;
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
