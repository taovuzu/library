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
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x] = i;
  }

  string s;
  cin >> s;

  if (s[0] == '1' || s[n - 1] == '1' || s[a[1] - 1] == '1' || s[a[n] - 1] == '1') {
    cout << -1 << "\n";
  }
  else {
    if (a[1] > a[n]) swap(a[1], a[n]);
    cout << 5 << "\n";
    cout << 1 << " " << a[1] << "\n";
    cout << 1 << " " << a[n] << "\n";
    cout << a[1] << " " << a[n] << "\n";
    cout << a[1] << " " << n << "\n";
    cout << a[n] << " " << n << "\n";
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