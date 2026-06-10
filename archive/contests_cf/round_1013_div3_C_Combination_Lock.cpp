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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());

    if(n % 2 == 0){
      cout << -1 << "\n";
    }
    else {
      for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
      }
    }
  }

  return 0;
}
