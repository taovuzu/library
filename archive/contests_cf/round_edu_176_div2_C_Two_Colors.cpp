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
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for(int i = 0; i < m; i++){
      cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;

    for(int i = 1; i < n ; i++){
      int j = n - i;
      int cnt = a.end() - lower_bound(a.begin(), a.end(), i);
      int cnt1 = a.end() - lower_bound(a.begin(), a.end(), j);
      ans += (cnt * cnt1 - min(cnt, cnt1));
    }

    cout << ans << "\n";
  }

  return 0;
}
