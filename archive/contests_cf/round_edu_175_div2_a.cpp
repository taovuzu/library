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
    cin>>n;
    int ans = (n/15)*3+1;
    for(int i=(n/15)*15+1;i<=n;i++){
      if(i%3==i%5) ans++;
    }
    cout<<ans<<"\n";
  }

  return 0;
}
