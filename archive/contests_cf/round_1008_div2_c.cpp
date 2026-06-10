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
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
      cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum0=0,sum1=0,sum=0;
    sum1=accumulate(a.begin()+n,a.end(),0LL);
    sum=accumulate(a.begin(),a.end(),0LL);
    sum0=(sum1-(sum-sum1));
    int l=a.back();
    vector<int> ans;
    if(sum0==l){
      sum1-=a[n];
      sum1+=a[n-1];
      sum0=(sum1-(sum-sum1));
      swap(a[n],a[n-1]);
    }
    if(sum0>l){
      ans.push_back(sum0);
      int i=0,j=n;
      while(i<n){
        ans.push_back(a[j]);
        ans.push_back(a[i]);
        i++,j++;
      }

    }
    else {
      ans.push_back(l);
      ans.push_back(l+l-sum0);
      ans.push_back(a[n-1]);
      int i=0,j=n;
      while(i+1<n){
         ans.push_back(a[j]);
        ans.push_back(a[i]);;
        i++,j++;
      }
    }
    for(int i=0;i<=2*n;i++){
      cout<<ans[i]<<" \n"[i==2*n];
    }
  }

  return 0;
}
