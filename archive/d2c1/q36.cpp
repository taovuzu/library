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

  int tt=1;  cin>>tt;
  while (tt--) {
    long double n,p,i,l,ans=1;
    cin>>n>>p>>i;
    cout<<fixed<<setprecision(4);
    l=1-p;
    if(p==0){
      cout<<"0.0000\n";
      continue;
    }
    ans*=p;
    for(int j=1;j<=i-1;j++){
      ans*=l;
    }
    long double temp=1;
    for(int j=1;j<=n;j++){
      temp*=l;
    }
    ans/=(1-temp);
    cout<<ans<<"\n";
  }

  return 0;
}
