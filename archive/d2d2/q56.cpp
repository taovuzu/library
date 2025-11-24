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
  string s;
  cin >> s;

  vector<int> a, b;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'l') b.push_back(i + 1);
    else a.push_back(i + 1);
  }

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
  for (int i = b.size() - 1; i >= 0; i--) {
    cout << b[i] << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
