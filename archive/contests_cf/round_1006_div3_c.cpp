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
    int n,x;
    cin>>n>>x;
    int num=0,count=0;
    for(int i=0;count<n-1;i++){
      if(i>x || i>=n){
        cout<<"0 ";
        count++;
        continue;
      }
      if((i|x)>x) continue;
      cout<<i<<" ";
      num|=i;
      count++;
    }
    int temp = ((~(num))&x);
    if(temp==0) temp = n-1;
    if((num|temp)!=x) temp=x;
    cout<<temp<<"\n";
    
  }

  return 0;
}
