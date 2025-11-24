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

  int n;
  while (cin >> n && n) {

    int x1 = 0, x2 = LLONG_MAX, y1 = 0, y2 = LLONG_MAX, z1 = 0, z2 = LLONG_MAX;

    for(int i = 0; i < n; i++){
      int x, y, z, l;
      cin >> x >> y >> z >> l;
      x1 = max(x, x1);
      x2 = min(x + l, x2);
      y1 = max(y, y1);
      y2 = min(y + l, y2 );
      z1 = max(z, z1);
      z2 = min(z + l, z2);
    }

    int ans = max(0LL , x2 - x1) * max(0LL, y2 - y1) * max(0LL, z2 - z1);
    cout << ans << "\n";
  }

  return 0;
}
