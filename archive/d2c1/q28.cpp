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
int v1,v2,t,d,rhs=0;


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>v1>>v2>>t>>d;
  int ans=0;
  for(int i=0;i<t;i++){  
   ans+=min(v1+i*d,v2+(t-i-1)*d);
  }
  cout<<ans<<"\n";

  return 0;
}

