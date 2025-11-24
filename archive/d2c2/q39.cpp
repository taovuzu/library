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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  int mini = min({a + b, a + c, b + d, c + d});
  int maxi = max({a + b, a + c, b + d, c + d});
  int ans = max(0LL, n * (mini + n - maxi));
  
  cout << ans << "\n";

  return 0;
}
