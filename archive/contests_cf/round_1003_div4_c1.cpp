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
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    for(int i=0;i<m;i++){
      cin>>b[i];
    }
    sort(b.begin(),b.end());
    for(int i=n-1;i>=0;i--){
      if(i==n-1){
        a[i]=max(a[i],b[m-1]-a[i]);
      }
      else{
        int maxAllowed = a[i+1] + a[i];
        int idx = upper_bound(b.begin(),b.end(),maxAllowed)-b.begin()-1;
        idx=max(idx,0LL);
        // pr(i,idx);
        if(a[i]>a[i+1]){
          a[i]=b[idx]-a[i];
        }
        else{
        if(a[i+1]>=b[idx]-a[i]){
           a[i]= max(a[i],b[idx]-a[i]);
          }
        }
      }
    }
    // pr(a);
    bool flag = is_sorted(a.begin(),a.end());
    cout<<(flag?"YES":"NO")<<"\n";
  }

  return 0;
}
