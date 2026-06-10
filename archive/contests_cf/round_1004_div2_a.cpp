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


bool isXMinus8(int x,int y){
  if((x-y)%9==8) return true;
  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int x,y;
    cin>>x>>y;
    bool flag =false;
    if((x+1 == y) || isXMinus8(x,y)){
      cout<<"Yes"<<"\n";
      flag=true;
    }
    if(!flag){
      cout<<"No"<<"\n";
    }
  }

  return 0;
}
