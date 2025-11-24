#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int x, y, q;
  cin >> x >> y >> q;
  set<int> xt;

  for (int i = 1; i * i <= max(x, y); i++) {
    if (x % i == 0 || y % i == 0) {
      if(x%i == 0 && y % i == 0) xt.insert(i);
      int temp1 = x / i;
      int temp2 = y / i;
      if (temp1 <= min(x, y) && y % temp1 == 0 && x % temp1 == 0) xt.insert(temp1);
      if (temp2 <= min(x, y) && x % temp2 == 0 && y % temp2 == 0) xt.insert(temp2);
      // pr(i, temp1, temp2);
    }
  }

  // pr(xt);

  while (q--) {
    int l, r;
    cin >> l >> r;
    auto it = xt.lower_bound(r);
    if (it != xt.begin() && (it == xt.end() || *it > r)) it--;
    if (it == xt.end() || *it < l) {
      cout << -1 << "\n";
    } else {
      cout << *it << "\n";
    }
  }

  return 0;
}
