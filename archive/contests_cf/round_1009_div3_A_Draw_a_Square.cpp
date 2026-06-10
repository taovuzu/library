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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b && b==c && c==d){
      cout<<"Yes"<<"\n";
    }
    else{
      cout<<"No"<<"\n";
    }
  }

  return 0;
}
