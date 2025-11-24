#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, a, b;
  cin >> n >> a >> b;

  vector<int> vt(n, 1);

  int sum = 1, maxi = 1;
  for (int i = 1; i <= b; i++) {
    vt[i] = sum + 1;
    sum += vt[i];
  }

  for (int i = max(b + 1, 2LL); i < n && i <= max(b, 1LL) + a; i++) {
    vt[i] = vt[i - 1] + 1;
  }

  sum = 1;
  for (int i = 1; i < n; i++) {
    if (vt[i] > sum)
      b--;
    else if (vt[i] > maxi)
      a--;
    sum += vt[i];
    maxi = max(vt[i], maxi);
  }

  int x = *max_element(vt.begin(), vt.end());
  if (a == 0 && b == 0 && x <= 50000) {
    for (int i = 0; i < n; i++) {
      cout << vt[i] << " \n"[i == n - 1];
    }
  } else {
    cout << -1 << "\n";
  }

  return 0;
}
