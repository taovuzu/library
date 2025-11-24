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

  int n;
  cin >> n;

  set<array<int,4>> xt;
  for(int i = 0; i < n; i++){
    int x, y, z;
    cin >> x >> y >> z;
    xt.insert({x, y, z, i + 1});
  }
  
  while(!xt.empty()){
    if(xt.size() == 2){
      auto a = *xt.begin();
      xt.erase(xt.begin());
      auto b = *xt.begin();
      xt.erase(xt.begin());
      cout << a[3] << " " << b[3] << "\n";
      pr(a,b);
    }
    else{
      auto a = *xt.begin();
      xt.erase(xt.begin());
      int y = a[1], z = a[2], o = a[3];

      auto b = *xt.begin();
      int x1 = b[0];

      auto it = xt.lower_bound({x1, y, z, -1});
      if(it == xt.end()) it--;
      auto c = *it;
      int y2 = c[1];

      auto it1 = xt.lower_bound({x1, y, z, -1});
      if(it1 == xt.end()) it1--;
      auto d = *it1;
      int o3 = d[3];

      pr(a);
      pr(b);
      pr(x1,y,z);
      pr(c);
      pr(x1,y2,z);
      pr(d);
      xt.erase(d);

      cout << o << " " << o3 << "\n";
    }
  }

  return 0;
}
