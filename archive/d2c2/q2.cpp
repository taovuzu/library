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

  int x,y;
  while(cin>>x>>y && x!=0 && y!=0){
    vector<int> a;
    int gcd = __gcd(x,y);
    while( x!=gcd && y!=gcd && x!=0 && y!=0){
      if(x>y) swap(x,y);
      a.push_back(y/x);
      y%=x;
    }
    a.push_back(1);
    reverse(a.begin(),a.end());
    vector<bool> b(a.size(),false);
    b[0]=true;
    for(int i=1;i<a.size();i++){
      bool flag=false;
      if(a[i]==1){
        flag=!b[i-1];
      }
      else{
        flag=true;
      }
      b[i]=flag;
    }
    // pr(a);
    // pr(b);
    cout<<(b[b.size()-1]?"Stan wins":"Ollie wins")<<"\n";
  }
  

  return 0;
}