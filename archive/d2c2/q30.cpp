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

  int n, k;
  cin >> n >> k;
  vector<int> a(n - 1);
  for (int i = 0; i + 1 < n; i++) {
      cin >> a[i];
  }

  Mint ans = 0;
  for (int i = 0; i + 1 < k; i++) {
      Mint term = ((i & 1) ? -1 : 1) * C(k, i) * (k - i) * power(Mint(k - 1 - i), n - 1);
      ans += term;
  }

  cout << ans << "\n";
  return 0;
}
