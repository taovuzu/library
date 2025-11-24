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
  int n,m,ans=0,shot=0;
  cin>>n;
  vector<int> c(n,-1);
  vector<array<int,3>> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i][0]>>a[i][1];
    a[i][2]=i;
  }
  sort(a.begin(),a.end());
  cin>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    shot++;
    int up = upper_bound(a.begin(), a.end(), array<int, 3>{x,0,0}, [](const array<int, 3>& lhs, const array<int, 3>& rhs) { return lhs[0] < rhs[0];  })-a.begin();
    int lw = up-1;
    pr(x,y,up,shot);
    if(up!=n){
      int xdis = x-a[up][0];
      double temp1= sqrtl(xdis*xdis+y*y);
      pr(temp1,xdis);
      if(temp1<=(1.0*a[up][1])){
        pr('.');
        if(c[a[up][2]]==-1) c[a[up][2]]=shot,ans++;
      }
    }
    if(lw!=-1){
      int xdis = x-a[lw][0];
      double temp2=sqrtl(xdis*xdis+y*y);
      pr(temp2,xdis);
      if(temp2<=(1.0*a[lw][1])){
        pr('_');
        if(c[a[lw][2]]==-1) c[a[lw][2]]=shot,ans++;
      }
    }
  }
  cout<<ans<<"\n";
  for(int i=0;i<n;i++){
    cout<<c[i]<<" \n"[i==n-1];
  }

  return 0;
}
