
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। ॥
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
  int n, k;
  cin >> n >> k;

  string a1, am;
  cin >> a1 >> am;

  int x1 = 0, xx = 0, xm = 0;

  for (int i = 0; i < n; i++) {
    char ch = a1[i] != am[i] ? '1' : '0';
    x1 += a1[i] == '1';
    xx += ch == '1';
    xm += am[i] == '1';
  }

  int tmp = ((1LL << k) + 1) / 3;
  int ans = tmp * x1 * (n - x1) + tmp * xx * (n - xx) + tmp * xm * (n - xm);
  int rem = ((1LL << k) + 1) % 3;
  if (rem >= 1) ans += x1 * (n - x1);
  if (rem >= 2) ans += xm * (n - xm);

  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt = 1;
  cin >> tt;

  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
