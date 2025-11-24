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

bool check (int n, int k , int x, int y, int z){
  if(x + y + z > n - k) return false;
  if((n - k - x - y - z) % 3 != 0) return false;
  int maxi = max({x, y, z});
  k -= (maxi - x);
  k -= (maxi - y);
  k -= (maxi - z);
  return k % 3 == 0 && k >= 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, k, d1, d2;
    cin >> n >> k >> d1 >> d2;
    bool flag = false;
    flag |= check(n, n - k, d1, 0, d2);
    flag |= check(n, n - k, d1 + d2, d2, 0);
    flag |= check(n, n - k, 0, d1, d1 + d2);
    flag |= check(n, n - k, d2 - min(d1, d2), d2 + d1 - min(d1, d2), d1 - min(d1, d2));

    cout << (flag ? "yes" : "no") << "\n";
  }

  return 0;
}
