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
  int n,m,ans=0;
  char a[105][105];
  vector<int> b(105,0);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  for(int j=0;j<m;j++){
    bool flag=true;
    for(int i=1;i<n;i++){
      if(!b[i] && a[i][j]<a[i-1][j]){
        flag=false;
        break;
      }
    }
    if(!flag){
      ans++;
    }
    else{
      for(int i=1;i<n;i++){
        if(a[i][j]!=a[i-1][j]) b[i]=1;
      }
    }
  }

  cout<<ans<<"\n";
  return 0;
}
