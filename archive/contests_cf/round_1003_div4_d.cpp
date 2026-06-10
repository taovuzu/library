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
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> b(n);  //sum,sTotal,idx;
    for(int i=0;i<n;i++){
      int sum=0,sTotal=0;
      for(int j=0;j<m;j++){
        cin>>a[i][j];
        sum+=a[i][j];
        sTotal+=(a[i][j]*(m-j));
      }
      b[i]={sum,sTotal,i};
    }
    sort(b.begin(),b.end(),[&](vector<int>x,vector<int> y){
      if(x[0]==y[0]){
        return x[1]>y[1];
      }
      return x[0]>y[0];
    });
    int total=n*m,ans=0,curr=0;
    for(int i=0;i<n;i++){
      int idx=b[i][2];
      for(int j=0;j<m;j++){
      ans+=(a[idx][j]*(total-curr));
        curr++;
      }
    }
    cout<<ans<<"\n";
  }

  return 0;
}
