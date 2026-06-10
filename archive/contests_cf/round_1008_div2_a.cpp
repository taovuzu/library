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
    int n,x;
    cin>>n>>x;
    int sum=0;
    for(int i=0;i<n;i++){
      int y;
      cin>>y;
      sum+=y;
    }
    bool flag=(sum/n==x && sum%n==0);
    cout<<(flag?"Yes":"No")<<"\n";
  }

  return 0;
}
