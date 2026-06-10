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
    string s;
    cin>>n>>s;
    int lo=0,hi=0;
    for(int i=0;i<n;i++){
      if(s[i]=='-') hi++;
      else lo++;
    }
    int ans = (hi-hi/2)*(lo)*(hi/2);
    cout<<ans<<"\n";
  }

  return 0;
}
