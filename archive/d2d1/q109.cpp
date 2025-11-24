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

int n, m, k;

bool check(int mid) {
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    cnt += min(mid / i, n);
  }
  return cnt >= k;
}

void solve() {
  cin >> n >> m >> k;

  int ans = n * m, lo = 1, hi = n * m;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid - 1;
      ans = mid;
    }
    else {
      lo = mid + 1;
    }
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
