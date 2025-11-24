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

  int n,a,b,c;
  int dp[4005];

  cin>>n>>a>>b>>c;
  dp[0]=0;
  for(int i=1;i<=n;i++){
    dp[i]=LLONG_MIN;
    int l1,l2,l3;
    l1=l2=l3=LLONG_MIN;
    if(i-a>=0) l1 = dp[i-a]==LLONG_MIN?LLONG_MIN:(dp[i-a]+1);
    if(i-b>=0) l2 = dp[i-b]==LLONG_MIN?LLONG_MIN:(dp[i-b]+1);
    if(i-c>=0) l3 = dp[i-c]==LLONG_MIN?LLONG_MIN:(dp[i-c]+1);
    dp[i]=max({l1,l2,l3,dp[i]});
  }
  cout<<dp[n]<<"\n";

  return 0;
}
