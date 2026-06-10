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
    int n,k,p;
    cin>>n>>k>>p;
    if(p*n<abs(k)){
      cout<<"-1\n";
    }
    else{
      int ans = abs(k)/p;
      if(k%p!=0) ans++;
      cout<<ans<<"\n";
    }
  }

  return 0;
}
