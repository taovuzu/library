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

int mex(int n){
  int lo=1,hi=500,ans=1;
  while(lo<=hi){
    int mid = (lo+hi)/2;
    if(2*n>=(mid*(mid+1))){
      ans=mid;
      lo=mid+1;
    }
    else hi=mid-1;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int k;
    cin>>k;
    vector<pair<int,int>> a;
    int last=0,y=0;
    while(k>0){
      int temp = mex(k);
      // pr(temp,k);
      a.push_back({last,y});
      last++;
      for(int i=0;i<temp;i++){
        a.push_back({last,y});
        last++;
      }
      last++;
      y++;
      k-=((temp*(temp+1))/2);
    }
    cout<<a.size()<<"\n";
    for(int i=0;i<a.size();i++){
      cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
  }

  return 0;
}
