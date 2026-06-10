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

    for(int i = 0; i < n; i++){
      cin >> a[i];
    }

    int ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

    cout << ans << "\n";
  }

  return 0;
}
