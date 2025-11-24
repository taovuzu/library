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
int a[15][2];
int dp[15][15];
int tracker[15][15];

// int rec(int l,int r){
//   if(l==r){
//     return 0;
//   }
//   if(dp[l][r]!=-1) return dp[l][r];
//   int ans=INT_MAX;
//   for(int p=l;p<r;p++){
//     int temp= a[l][0]*a[p][1]*a[r][1]+rec(l,p)+rec(p+1,r);
//     if(temp<ans){
//       ans=temp;
//       tracker[l][r]=p;
//     }
//   }
//   return dp[l][r]=ans;
// }

void printer(int l,int r){
  if(l==r){
    cout<<"A"<<l+1;
    return;
  }
  cout<<"(";
  printer(l,tracker[l][r]);
  cout<<" x ";
  printer(tracker[l][r]+1,r);
  cout<<")";
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t=0;
  while(++t){
    cin>>n;
    if(!n) break;
    for(int i=0;i<n;i++){
      cin>>a[i][0]>>a[i][1];
    }

    for(int l=n-1;l>=0;l--){
      for(int r=l;r<n;r++){
        if(l==r){
          dp[l][r]=0;
          continue;
        }
        int ans=INT_MAX;
        for(int p=l;p<r;p++){
          int temp= a[l][0]*a[p][1]*a[r][1]+dp[l][p]+dp[p+1][r];
          if(temp<ans){
            ans=temp;
            tracker[l][r]=p;
          }
        }
        dp[l][r]=ans;
      }
    }

    cout<<"Case "<<t<<": ";
    printer(0,n-1);
    cout<<"\n";
  }

  return 0;
}
