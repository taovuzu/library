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

  int n,q,c,t,X1,Y1,X2,Y2;
  cin>>n>>q>>c;
  vector<vector<vector<int>>> b(105, vector<vector<int>>(105, vector<int>(11, 0)));

  for (int i = 0; i < n; i++) {
    int X, Y, s;
    cin >> X >> Y >> s;
    b[X][Y][s]++;
  }

  for (int k = 0; k <= 10; k++) {
    for (int i = 1; i < 105; i++) {
      for (int j = 1; j < 105; j++) {
          b[i][j][k] += b[i-1][j][k] + b[i][j-1][k] - b[i-1][j-1][k];
      }
    }
  }


  while(q--){
    cin>>t>>X1>>Y1>>X2>>Y2;
    int ans=0;
    // pr(t,X1,Y1,X2,Y2);
    for(int i=0;i<=10;i++){
      int cnt = (b[X2][Y2][i]-b[X2][Y1-1][i]-b[X1-1][Y2][i]+b[X1-1][Y1-1][i]);
      // pr(i,cnt);
      ans+=(((i+t)%(c+1))*cnt);
    }
    cout<<ans<<"\n";
  }


  return 0;
}