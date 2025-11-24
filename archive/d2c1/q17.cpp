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

  int n,m,k;
  cin>>n>>m>>k;
  vector<int> a(n+1),b(m+1);
  iota(a.begin(),a.end(),0);
  iota(b.begin(),b.end(),0);
  vector<vector<int>> c(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>c[i][j];
    }
  }
  while(k--){
    char ch;
    int i,j;
    cin>>ch>>i>>j;
    if(ch=='r'){
      swap(a[i],a[j]);
    }
    else if(ch=='c'){
      swap(b[i],b[j]);
    }
    else{
      i=(a[i]-1),j=(b[j]-1);
      cout<<c[i][j]<<"\n";
    }
  }

  return 0;
}
