/* Embrace boredom and hard work; only through relentless discipline does mastery unlock a universe of true pleasure. */
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

  int n, x, y, ans = 0;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    if(x + 1 > ans) ans = x + 1;
    y--;
    while(y > 0) {
      x++;
      y >>= 2;
    }
    if(x > ans) ans = x;
  }

  cout << ans << "\n";

  return 0;
}
