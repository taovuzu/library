// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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
  int n;
  cin >> n;

  vector<int> f(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }

  vector<int> a(n + 5);
  for (int i = 1; i <= n - 2; i++) {
    a[i + 1] = (f[i] + f[i + 2] - 2 * f[i + 1]) / 2;
  }

  int sum = 0, sum1 = 0;
  for (int i = 2; i <= n - 1; i++) {
    sum += (i - 1) * a[i];
    sum1 += a[i];
  }

  a[n] = (f[1] - sum) / (n - 1);
  a[1] = sum1 + a[n] - (f[1] - f[2]);

  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }

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
