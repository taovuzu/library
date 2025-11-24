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

  int n;
  cin>>n;
  int ans=1,x=1,y=2,z=1;
  while(z<=n){
    z=x+y;
    x=y;
    y=z;
    ans++;
  }
  cout<<ans-1<<"\n";

  return 0;
}
