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

  int n, k;
  cin >> n >> k;
  k--;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int x = a[k / n];

  int cnt = 0, d = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] < x) cnt++;
    else if(a[i] == x) d++;
  }

  k -= cnt * n;
  int y = a[k / d];

  cout << x << " " << y;

  return 0;
}
