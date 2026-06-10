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
  int n, m;
  string s;
  cin >> n >> m >> s;
  set<int> xt;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    xt.insert(x);
  }
  for (int i = 0, j = 1; i < n; i++) {
    if (i) {
      if (s[i - 1] == 'B') while (xt.find(++j) != xt.end());
    }
    if (s[i] == 'A') j++;
    else {
      while (xt.find(++j) != xt.end());
    }
    xt.insert(j);
  }
  cout << xt.size() << "\n";
  for (auto x : xt) {
    cout << x << " ";
  }
  cout << "\n";
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
