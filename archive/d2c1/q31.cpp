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

  int n,m;
  int t=0;
  while(cin>>n>>m && (n!=0 || m!=0) && ++t){
    int x = ((m-1)*m)/2;
    int y = ((n-1)*n)/2;
    int ans = x*y;
    cout<<"Case "<<t<<":"<<" "<<ans<<"\n";
  }

  return 0;
}
