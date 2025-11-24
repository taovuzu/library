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

string s;
int dp[305][305];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(cin>>s){
    int n=s.size();
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j]=0;
      }
    }
    for(int l=n-1;l>=0;l--){
      for(int r=n-1;r>=l;r--){
        if(l==r){
          dp[l][r]=1;
          continue;
        }
        if(s[l]==s[r]){
          int ans=0;
          for(int p=l+1;p<=r;p++){
            if(s[p]==s[l]){
              ans=(ans+(dp[l+1][p-1]*dp[l][r]%(1000000000))%(1000000000));
            }
          }
          dp[l][r]=ans%(1000000000);
        }
        
      }
    }

    cout<<dp[0][n-1]<<"\n";
  }

  return 0;
}
