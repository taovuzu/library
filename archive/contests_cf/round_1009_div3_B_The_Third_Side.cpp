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
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a.begin(),a.end());
    while(a.size()>1){
      int x=a.back();
      a.pop_back();
      int y=a.back();
      a.pop_back();
      a.push_back(x+y-1);
    }
    cout<<a.back()<<"\n";
  }

  return 0;
}
