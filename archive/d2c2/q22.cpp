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
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int l = 0, r = 0, ans = 0;
  while (l < n){
    while(r < n && a[l] == a[r]) r++;
    ans += ((r - l)* (r - l + 1)) / 2;
    l = r;
  }
  cout << ans << "\n";

  return 0;
}
