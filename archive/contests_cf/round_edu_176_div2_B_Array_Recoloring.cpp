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
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int ans = 0;
    if (k == 1) {
      ans = max(a[n - 1] + *max_element(a.begin(), a.begin() + n - 1), a[0] + *max_element(a.begin() + 1, a.end()));
    } else {
      sort(a.rbegin(), a.rend());
      ans = accumulate(a.begin(), a.begin() + k + 1, 0LL);
    }
    cout << ans << "\n";
  }

  return 0;
}
