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
    int n;
    cin>>n;
    int lo=1,hi=n,mid=2,last;
    bool flag=true;
    while(true){
      cout<<"? "<<lo<<" "<<mid<<" "<<hi<<endl;
      cout.flush();
      cin>>last;
      if(last==-1){
        return 0;
      }
      else{
        if(last==0){
          break;
        }
        else{
          if(flag){
            mid=last;
            flag=false;
          }
          else{
            hi=last;
            flag=true;
          }
        }
      }
    }
    cout<<"! "<<lo<<" "<<mid<<" "<<hi<<endl;
    cout.flush();
  }

  return 0;
}
