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

int n, m, k;

bool check(int mid){
  int seg = ((m + 1) / (mid + 1));
  int maxi = seg * mid;
  maxi += max((m - seg * (mid + 1)), 0LL);
  return maxi * n >= k;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin >> n >> m >> k;

    int ans = m;
    int lo = 1, hi = m;
    pr(tt);
    while(lo <= hi){
      int mid = (lo + hi) / 2;
      pr(lo, hi, mid);
      pr(check(mid));
      if(check(mid)){
        ans = mid;
        hi = mid - 1;
      }
      else{
        lo = mid + 1;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
