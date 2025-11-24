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

  int r, nb, ns, nc, pb, ps, pc;
  string s;
  cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;

  int lo = 0 , hi = 1e13, ans = 0;

  int bc = 0, bs = 0, bb = 0 ;   // count of items required;
  for(auto it: s){
    if(it == 'C') bc++;
    if(it == 'S') bs++;
    if(it == 'B') bb++;
  }

  while( lo <= hi){
    int mid = (lo + hi) / 2;
    int price = max(0LL, (mid * bb - nb))* pb + max(0LL, (mid * bc - nc)) * pc + max(0LL, (mid * bs - ns)) * ps;
    if(price <= r){
      ans = mid;
      lo = mid + 1;
    }
    else hi = mid -1;
  }

  cout << ans << "\n";

  return 0;
}
