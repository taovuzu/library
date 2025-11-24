// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

const double EPS = 1e-9;

int n, k;
double l, v1, v2;

int dcmp(double a, double b) {	return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;	}


bool check(double mid) {
  int groups = (n + k - 1) / k;
  double busTime = (l - v1 * mid) / (v2 - v1);
  double gapDis = (v2 - v1) * busTime;
  double backTime = gapDis / (v2 + v1);
  double time = busTime * groups + backTime * (groups - 1);
  return dcmp(time , mid) <= 0;
}

void solve() {
  cin >> n >> l >> v1 >> v2 >> k;
  double lo = 0, hi = 1e9, ans = 1e9;
  for (int i = 0; i < 80; i++) {
    double mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = mid;
      hi = mid;
    }
    else lo = mid;
  }

  cout << setprecision(9) << fixed << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
