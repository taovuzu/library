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
    int n;
    cin>>n;
    vector<int> f(2*n+2);
    for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      f[x]++;
    }
    bool flag=true;
    for(int i=1;i<=2*n;i++){
      if(f[i]==0) continue;
      if(f[i]==1) {
        flag=false;
        break;
      }
      f[i]-=2;
      f[i+1]+=f[i];
    }
    cout<<(flag?"Yes":"No")<<"\n";
  }


  return 0;
}
