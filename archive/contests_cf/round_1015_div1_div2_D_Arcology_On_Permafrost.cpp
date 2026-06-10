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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;

    int x = 0;
    int div = n / (n - m * k);
    int mex = min({n - m * k, max({div, m})});

    pr(mex, div);
    for(int i = 0; i < n; i++) {
      cout << x % mex << " \n"[i == n - 1];
      x++;
    }

  }

  return 0;
}
