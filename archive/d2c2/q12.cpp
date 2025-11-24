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
  vector<int> a(n);
  int gcd = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(gcd == 0) gcd = a[0];
    else gcd = __gcd(a[i], gcd);
  }

  int ans = *max_element(a.begin(), a.end()) / gcd - n;

  cout << ((ans & 1) ? "Alice" : "Bob") << "\n";

  return 0;
}
