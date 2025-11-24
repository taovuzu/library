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

  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1), b;
  a[n] = (1e9);

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  for(int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    if(x == 1) b.push_back(y);
  }
  
  sort(b.begin(), b.end());

  int ans = m, j = 0;
  for(int i = 0; i <= n; i++){
    while(j < b.size() && b[j] < a[i]) j++;
    int spells = (i + b.size() - j);

    ans = min(ans, spells);
  }

  cout << ans << "\n";

  return 0;
}
