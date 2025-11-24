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

long double x,y,x1,y1,n,z1,z2,z3;
int ans=0;

bool check(){
  return (z1*x+z2*y+z3)*(z1*x1+z2*y1+z3)<0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>x>>y>>x1>>y1>>n;

  while(n--){
    cin>>z1>>z2>>z3;
    if(check()){
      ans++;
    }
  }

  cout<<ans<<"\n";

  return 0;
}
