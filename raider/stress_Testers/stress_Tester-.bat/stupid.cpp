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

  int n,x;
  cin>>n>>x;
  multiset<array<int,3>> xt,xt1; // {duration,start,cost},{duration,end,cost};
  int ans=LLONG_MAX;
  for(int i=0;i<n;i++){
    int l,r,c;
    cin>>l>>r>>c;
    int dur = r-l+1;
    auto it = xt.lower_bound({x-dur,r+1,0});      // big
    if(it!=xt.end()){
      array<int,3> a= *it;
      if(a[0]==x-dur){
        pr('a',l,r,c);
        debarr(a,3);
        ans = min(ans,a[2]+c);
      }
    }
    it = xt1.upper_bound({x-dur-1,LLONG_MAX,LLONG_MAX});      // small
    if(it!=xt1.end()){
      array<int,3> a= *it;
      if(a[0]==x-dur && a[1]<l){
        pr('b',l,r,c);
        debarr(a,3);
        ans = min(ans,a[2]+c);
      }
    }
    xt.insert({dur,l,c});
    xt1.insert({dur,r,c});
  }
  cout<<(ans==LLONG_MAX?-1:ans)<<"\n";

  return 0;
}
