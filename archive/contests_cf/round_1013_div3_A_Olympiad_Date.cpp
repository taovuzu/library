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
    vector<int> b(11, 0);
    int ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      b[x]++;
      if(b[0] >= 3 && b[1] >= 1 && b[2] >= 2 && b[3] >= 1 && b[5] >= 1){
        ans = min(ans, i + 1);
      }
    }

    ans = ans == LLONG_MAX ? 0 : ans;
    cout << ans << "\n";
  }

  return 0;
}
