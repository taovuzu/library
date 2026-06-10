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

int x, y, k;
bool check(int mid) {
  __int128 cur = mid;
  int steps = x;

  while (steps > 0) {
    int t = cur / y;
    if (t == 0) break;

    __int128 limit = (__int128)t * y;
    __int128 need = cur - limit;
    int s = need / t + 1;

    if (s > steps) s = steps;

    cur -= (__int128)t * s;
    steps -= s;

    if (cur < k) return false;
  }

  return cur >= k;
}



void solve() {
  cin >> x >> y >> k;

  const int maxi = 1e12;
  int lo = 1, hi = 1e18, ans = hi;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }

  cout << (ans > maxi ? -1 : ans) << "\n";
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
