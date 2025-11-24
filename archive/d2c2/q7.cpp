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


signed
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  int mex = LLONG_MAX;
  for(int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    mex = min(r - l + 1, mex);
  }
  
  cout << mex << "\n";
  for(int i = 0; i < n; i++){
    cout << (i % mex) << " \n"[i==n-1];
  }

  return 0;
}
