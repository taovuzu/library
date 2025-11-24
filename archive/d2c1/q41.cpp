#include <bits/stdc++.h>

using namespace std;

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

  int n,m;
  cin>>n>>m;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  double ans = 0.0;
  while(m--){
    int u,v;
    double e;
    cin>>u>>v>>e;
    ans = max(ans,(a[u]+a[v])/e);
  }
  cout<<fixed<<setprecision(10)<<ans<<"\n";

  return 0;
}
