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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
      if(k&1){
        if(i==n){
          cout<<n-1<<" ";
        }
        else{
          cout<<n<<" ";
        }
      }
      else{
        if(i==n-1){
          cout<<n<<" ";
        }
        else{
          cout<<n-1<<" ";
        }
      }
    }
    cout<<"\n";
  }

  return 0;
}
