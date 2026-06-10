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

vector<int> ans(500100);

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  iota(ans.begin(),ans.end(),0);
  swap(ans[1], ans[2]);
  swap(ans[8], ans[9]);
  swap(ans[49], ans[50]);
  swap(ans[288], ans[289]);
  swap(ans[1681], ans[1682]);
  swap(ans[9800], ans[9801]);
  swap(ans[57121], ans[57122]);
  swap(ans[332928],ans[332929]);
  
  while (tt--) {
    int n;
    cin>>n;
    int total = (n*(n+1))/2;
    int sq = sqrtl(total);
      // 1 8 49 288 1681 9800 57121

    if(sq*sq==total){
      cout<<"-1"<<"\n";
    }
    else{
      for(int i=1;i<=n;i++){
        cout<<ans[i]<<" \n"[i==n];
      }
    }
  }

  return 0;
}
