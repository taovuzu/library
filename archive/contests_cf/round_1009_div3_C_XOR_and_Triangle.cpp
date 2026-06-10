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

bool isT(int x, int y, int z) {
  return (x + y > z && y + z > x && z + x > y);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int x;
    cin>>x;
    int num = log2(x)+1,y=1;
    for(int j=1;j+1<num;j++){
      y|=(1<<j);
    }
    int z =x^y;
    if(!isT(x,y,z)){
      cout<<"-1"<<"\n";
    }
    else{
      cout<<y<<"\n";
    }
  }

  return 0;
}
