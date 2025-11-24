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
  if(x == 3){
    cout << 5 << "\n";
  }
  else{
    for(int i = 1; i <= 100; i += 2){
      int range = (i * i + 1) / 2;
      if(x <= range ){
        cout << i << "\n";
        break;
      }
    }
  }

  return 0;
}
