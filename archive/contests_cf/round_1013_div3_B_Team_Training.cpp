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
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for(int i = 0; i <n; i++){
      cin >> a[i];
    }
    
    sort(a.rbegin(), a.rend());
    int ans = 0, last = 0;
    for(int i = 0; i < n; i++){
      last++;
      if(a[i] * last >= x){
        ans++;
        last = 0;
      }
    }
    
    cout << ans << "\n";
  }

  return 0;
}
