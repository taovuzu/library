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
  if(n & 1){
    cout << "YES" << "\n";
    for(int i = 1; i <= n; i++){
      int x = 2 * i - (1 & i);
      cout << x << " ";
    }
    for(int i = 1; i <= n; i++){
      int x = 2 * i - (1 & (i - 1));
      cout << x << " ";
    }
  }
  else {
    cout << "NO" << "\n";
  }

  return 0;
}
