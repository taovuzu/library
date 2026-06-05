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

int n;
double x;

bool check (double mid) {
  double last = mid, slast = x;
  for (int i = 3; i <= n; i++) {
    double curr = 2 * last - slast + 2;
    if (curr < 0) return false;
    slast = last;
    last = curr;
  }

  return true;
}

void solve() {
  double lo = 0, hi = x, ans = hi;
  for (int i = 0; i <= 80; i++) {
    double mid = (lo + hi) / 2.0;
    if (check(mid)) {
      ans = mid;
      hi = mid;
    }
    else {
      lo = mid;
    }
  }

  double last = ans, slast = x;
  for (int i = 3; i <= n; i++) {
    double curr = 2 * last - slast + 2;
    slast = last;
    last = curr;
  }

  cout << setprecision(2) << fixed << last << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n >> x) {
    solve();
  }

  return 0;
}
