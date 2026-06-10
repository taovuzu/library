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

vector<int> a(2005);
// vector<int> b(2005);
int n;

// int inv(){
//   for(int i=0;i<n;i++){
//     int counter=0;
//     for(int j=i+1;j<n;j++){
//       if(a[j]<a[i]) counter++;
//     }
//     b[i]=counter;
//   }

// }



signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    // inv();
    int maxR=0,l=1,r=1;
    for(int i=0;i<n-1;i++){
      // if(b[i]==0) continue;
      int gt=0,lw=0;
      for(int j=i+1;j<n;j++){
        if(a[j]>a[i]) gt++;
        else if(a[j]<a[i]) lw++;
        int hp = -gt+lw;
        if(hp>maxR){
          l=i+1,r=j+1;
          maxR=hp;
        }
      }
    }
    // pr(maxR);
    cout<<l<<" "<<r<<"\n";
  }

  return 0;
}
