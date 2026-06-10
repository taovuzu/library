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
  vector<int> a(n), b(n);
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int l = __gcd(a[i], i > 0 ? a[i - 1] : 1LL);
    int r = __gcd(a[i], i < n - 1 ? a[i + 1] : 1LL);
    int x = l * r / __gcd(l, r);
    if (x < a[i]) ans++;
  }

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
