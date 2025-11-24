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
  cin.tie(0);
  cout.tie(0);

  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(200100, 0);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++, a[r + 1]--;         // sweep line
  }

  for (int i = 1; i < 200100; i++) {
    a[i] += a[i - 1];         
  }


  for (int i = 1; i < 200100; i++) {
    if(a[i] >= k) a[i] = 1;
    else a[i] = 0;
    a[i] += a[i - 1];
  }


  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[l - 1] << "\n";
  }

  return 0;
}