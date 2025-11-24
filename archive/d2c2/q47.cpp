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

  int n, q;
  cin >> n >> q;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i != 0) a[i] += a[i - 1];
  }

  vector<int> b(q);
  for(int i = 0; i < q; i++){
    cin >> b[i];
  }

  int power = 0;
  for(int i = 0; i < q; i++){
    power += b[i];
    int j = upper_bound(a.begin(), a.end(), power) - a.begin() - 1;
    if(j == n - 1){
      cout << n << "\n";
      power = 0;
    }
    else{
      cout << (n - 1 - j) << "\n";
    }
  }

  return 0;
}
