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

  int n;
  cin >> n;

  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  b[0] = a[0];
  int sum = accumulate(a.begin(), a.end(), 0LL);
  int target = sum / 3;
  for(int i = 1; i < n; i++){
    b[i] = a[i] + b[i - 1];
    c[i] = c[i - 1] + (b[i] == target * 2);
  }

  int ans = 0;
  if(sum % 3 == 0 && n >= 3) {
    for(int i = 0; i < n - 1; i++){
      if(b[i] == target) {
        ans += (c[n - 2] - c[i]);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
