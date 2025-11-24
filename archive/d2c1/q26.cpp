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

  int h,n;
  cin>>h>>n;
  string s="";
  while(s.size()<h){
    if(n&1) s+="L";
    else s+="R";
    n=(n+1)/2;
  }
  reverse(s.begin(),s.end());
  char last='R';
  int ans=0;
  for(int i=0;i<h;i++){
    if(s[i]!=last) ans++;
    else {
      ans += (1LL<<(h-i));
    }
    last=s[i];
  }
  cout<<ans<<"\n";

  return 0;
}
