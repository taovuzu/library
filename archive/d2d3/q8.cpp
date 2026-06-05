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

int n, target;
vector<double> prob(5);
vector<int> a(5);

bool check(double mid) {
  double exp = 0, sum = accumulate(a.begin(), a.end(), 0LL);
  for (int mask = 0; mask < (1 << n); mask++) {
    double tmp = 1, x = 0;
    int cnt = __builtin_popcountll(mask);
    for (int i = 0; i < n; i++) {
      if (1 & (mask >> i)) {
        tmp *= prob[i];
        if (cnt == 1) {
          x = a[i] + mid * a[i];
        }
      }
      else {
        tmp *= (1.0 - prob[i]);
      }
    }
    exp += tmp * (sum - x);
  }

  return target <= exp;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> prob[i];
    prob[i] /= 100.0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> target;

  double lo = 0, hi = 1e15, ans = -1;
  for (int i = 0; i <= 90; i++) {
    double mid = (lo + hi) / 2.0;
    if (check(mid)) {
      ans = mid;
      lo = mid;
    }
    else {
      hi = mid;
    }
  }

  cout << (ans == 1e15 ? -2 : ans) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}