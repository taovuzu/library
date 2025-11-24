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

bool isCubic(int x,int y){
  int prod=x*y,lo=1,hi=1e6,ans=1;
  while(lo<=hi){
    int mid=(lo+hi)/2;
    if(mid*mid*mid<=prod){
      ans=mid;
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }
  return (ans*ans*ans==prod) && (x%ans==0) && (y%ans==0);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    bool flag = isCubic(x,y);
    cout<<(flag?"Yes":"No")<<"\n";
  }

  return 0;
}
