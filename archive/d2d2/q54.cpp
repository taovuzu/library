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

void solve() {
  string s, s1 = "";
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    s1 += s[i];
    int n = s1.size();
    while (n >= 3 && s1[n - 1] == s1[n - 2] && s1[n - 2] == s1[n - 3]) {
      s1.pop_back();
      n = s1.size();
    }
    while (n >= 4 && s1[n - 1] == s1[n - 2] && s1[n - 3] == s1[n - 4]) {
      s1.pop_back();
      n = s1.size();
    }
  }

  cout << s1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
