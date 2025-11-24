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

int n;

int dp[1005][1005];
int cuts[55];

int rec(int l,int r){
  if(l+1==r){
    return 0;
  }
  if(dp[l][r]!=-1) return dp[l][r];
  int ans=INT_MAX;
  for(int p=l+1;p<r;p++){
    ans = min(ans,cuts[r]-cuts[l]+rec(l,p)+rec(p,r));
  }
  return dp[l][r]=ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  while(true){
    int ll=1;
    cin>>ll;
    if(!ll){
      break;
    }
    cin>>n;
    for(int i=0;i<=ll+1;i++){
      for(int j=0;j<ll;j++){
        dp[i][j]=-1;
      }
    }
    for(int i=1;i<=n;i++){
      cin>>cuts[i];
    }
    cuts[0]=0;
    cuts[n+1]=ll;
    cout<<"The minimum cutting is "<<rec(0,n+1)<<".\n";
  }

  return 0;
}
