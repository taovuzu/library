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
    string s;
    cin>>s;
    if(s.size()>=2){
      s.pop_back();
      s.pop_back();
      s+="i";
    }
    cout<<s<<"\n";
  }

  return 0;
}
