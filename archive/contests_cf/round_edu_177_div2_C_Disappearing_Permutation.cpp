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
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }

    vector<int> bel(n, -1), siz(n);
    for(int x = 0; x < n; x++) {
      if (bel[x] != -1) {
        continue;
      }
      for (int i = x; bel[i] == -1; i = a[i]) {
        bel[i] = x;
        siz[x]++;
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      ans += siz[bel[x]];
      siz[bel[x]] = 0;
      cout << ans << " \n"[i == n - 1];
    }
  
  }

  return 0;
}
