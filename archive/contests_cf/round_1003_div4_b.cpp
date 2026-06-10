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
    string s;
    cin>>s;
    int i=0,n=s.size();
    bool flag=false;
    while(i+1<n){
      if(s[i]==s[i+1]){
        flag=true;
        break;
      }
      i++;
    }
    if(flag){
      cout<<"1"<<"\n";
    }
    else{
      cout<<n<<"\n";
    }
  }

  return 0;
}
