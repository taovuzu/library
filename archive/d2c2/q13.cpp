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

  if(n <= 5){
    cout << "-1" << "\n";
  }
  else {
    cout << "1 2" << "\n" << "2 3" << "\n" << "2 4" << "\n" << "1 5" << "\n";
    int last = 6;
    while(last <= n){
      cout << 1 << " " << last << "\n";
      last++;
    }
  }
  
  for(int i = 2; i <= n; i++){
    cout << 1 << " " << i << "\n";
  }

  return 0;
}
