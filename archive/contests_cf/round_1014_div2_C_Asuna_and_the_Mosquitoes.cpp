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

    int b[2] = {0, 0};
    for(int i = 0; i < n; i++){
      cin >> a[i];
      b[a[i] % 2]++;
    }

    int ans;
    if(b[0] == 0 || b[1] == 0) {
      ans = *max_element(a.begin(), a.end());
    }
    else {
      ans = accumulate(a.begin(), a.end(), 0LL) - b[1] + 1;
    }

    cout << ans << "\n";
  }

  return 0;
}
