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

bool can(int m, int s) {
  return s >= 0 && s <= 9 * m;
}

void solve() {
  int m, s;
  cin >> m >> s;
  string ans = "", ans1 = "";
  int sum = s;
  for (int i = 0; i < m; i++) {
    for (int d = 0; d < 10; d++) {
      if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d)) {
        ans += char('0' + d);
        sum -= d;
        break;
      }
    }
  }
  sum = s;
  for (int i = 0; i < m; i++) {
    for (int d = 9; d >= 0; d--) {
      if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d)) {
        ans1 += char('0' + d);
        sum -= d;
        break;
      }
    }
  }
  if (ans.size() != m) ans = "-1", ans1 = "-1";
  cout << ans << " " << ans1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
