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

  int x;
  cin >> x;
  vector<int> a(x);
  for(int i = 0; i < x; i++){
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  for(int i = 1; i < x; i++){
    a[i] += a[i-1];
  }

  int ans = 0, n = x;
  while(n >= 1){
    ans += a[x / n - 1];
    n /= 4;
  }
  cout << ans << "\n";

  return 0;
}
