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
  while(cin>>n && n){
    int ans=1,j,k;
    int sq = sqrt(abs(n));
    for(int i=-sq;i<=sq;i++){
      if(i==-1 || i==0 || i==1) continue;
      for(j=1,k=0;j<abs(n) && j>(-abs(n));j*=i,k++);
      if(j==n){
        ans = max(ans,k);
      }
    }
    cout<<ans<<"\n";
  }

  return 0;
}
