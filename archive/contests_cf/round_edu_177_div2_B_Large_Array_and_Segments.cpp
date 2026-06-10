/* practice with Dukkha */
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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(i == 0) b[i] = a[0];
      else b[i] = a[i] + b[i - 1];
    }

    int ans = 0;
    pr(a);
    pr(b);
    for(int i = 0; i < n; i++) {
      int sum = b[n - 1];
      if(i > 0) sum -= b[i - 1];
      int alpha = max((x - sum + b[n - 1] - 1) / b[n - 1], 0LL);
      ans += max((k - alpha), 0LL);
      pr(sum);
      pr(alpha);
      pr(ans);
    }

    cout << ans << "\n";
  }

  return 0;
}
