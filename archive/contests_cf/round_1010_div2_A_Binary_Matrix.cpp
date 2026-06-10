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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m,0));
    vector<int> r(n,0),c(m,0);
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      for(int j=0;j<m;j++){
        a[i][j]=s[j]-'0';
        r[i]+=a[i][j];
        c[j]+=a[i][j];
      }
    }
    int  rc = 0, cc = 0;

    for(int i = 0; i < n; i++){
      if(r[i] & 1) rc++;
    }

    for(int i = 0; i < m; i++){
      if(c[i] & 1) cc++;
    }

    cout << max(rc,cc) << "\n";
  }

  return 0;
}
