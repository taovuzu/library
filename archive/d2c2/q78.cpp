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

  int n, m, k;
  cin >> n >> m >> k;

  cout << (m * (m - 1)) / 2 << "\n";
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= m - i; j++) {
      if(k) cout << j + 1 << " " << j << "\n";
      else cout << j << " " << j + 1 << "\n";
    }
  }

  return 0;
}
