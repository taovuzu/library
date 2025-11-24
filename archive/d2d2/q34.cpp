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

int m, k;

int ncr(int n, int r) {   // max range is 124 for __int128
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  __int128 res = 1;
  for (int i = 1; i <= r; ++i) {
    res = res * (n - r + i) / i;
  }
  return res;
}

int rcx(int x) {
  bitset<64> bt(x);
  int ans = (bt.count() == k);
  for (int i = 63, cnt = 0; i >= 0 && cnt < k; i--) {
    if (bt[i]) {
      ans += ncr(i, k - cnt);
      cnt++;
    }
  }
  return ans;
}

void solve() {
  cin >> m >> k;
  int lo = 1, hi = 1e18, ans = 1e18;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (rcx(mid << 1) - rcx(mid) >= m) {
      hi = mid - 1;
      ans = mid;
    }
    else lo = mid + 1;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
