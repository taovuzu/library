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

  int k;
  while(cin>>k){
    int count=0;
    vector<vector<int>> a;
    for(int i=k+1;i<=2*k;i++){
      int y = i;
      int x = (k*y)/(y-k);
      if(x*y==k*(x+y)){
        count++;
        a.push_back({y,x});
      }
    }
    cout<<count<<"\n";
    for(int i=0;i<count;i++){
      cout<<"1/"<<k<<" = "<<"1/"<<a[i][1]<<" + "<<"1/"<<a[i][0]<<"\n";
    }
  }

  return 0;
}
