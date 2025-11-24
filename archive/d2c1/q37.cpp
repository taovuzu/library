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

__int128 pascle[101][101];

void ck() {
  for (int i = 0; i < 101; i++) {
      pascle[i][0] = 1;
      for (int j = 1; j <= i; j++) {
          pascle[i][j] = pascle[i - 1][j] + pascle[i - 1][j - 1];
      }
  }
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ck();
  while(true){
    int m,w,c;
    cin>>m>>w>>c;
    cout<<fixed<<setprecision(7);
    if(m==0 && w==0) return 0;
    double ans = 0, p1 = ((double)m)/(m+w);
    double p2=1-p1;
    for(int i=0;i<=c;i+=2){
      __int128 ways = pascle[c][i];
      double res = pow(p1,i)*pow(p2,c-i);
      ans+=(ways*res);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
