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

int a[1005][1005];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,q;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }

  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans+=(a[i][j]*a[j][i]);
    }
  }
  cin>>q;
  while(q--){
    int t,x;
    cin>>t;
    if(t==1){
      cin>>x;
      x--;
      for(int i=0;i<n;i++){
        if(a[x][i] && a[i][x]){
          ans-=2;
          if(i==x) ans++;
        }
        else if(a[x][i]==0 && (i==x)?1:a[i][x]){
          ans+=2;
          if(i==x) ans--;
        }
        a[x][i]=(!a[x][i]);
      }
    }
    else if(t==2){
      cin>>x;
      x--;
      for(int i=0;i<n;i++){
        if(a[i][x] && a[x][i]){
          ans-=2;
          if(i==x) ans++;
        }
        else if(a[i][x]==0 && (i==x)?1:a[x][i]){
          ans+=2;
          if(i==x) ans--;
        }
        a[i][x]=(!a[i][x]);
      }
    }
    else{
      cout<<(ans&1);
    }
    // if(ans) debmat(a,n,n);
    pr(x,ans);
  }

  return 0;
}
