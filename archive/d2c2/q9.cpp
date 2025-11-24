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
  cin.tie(0);
  cout.tie(0);

  int n, p;
  cin >> n >> p;
  vector<long double> a(n); 
  for(int i = 0; i < n; i++){
    int l, r;
    cin >> l >> r;
    a[i] = (long double) ( r / p - (l - 1) / p)  / ( r - l + 1);
  }
  
  long double cost = 0;
  for (int i = 0; i < n; i++) {
    cost += 1 - (1 - a[i]) * (1 - a[(i + 1) % n]);
  }

  cost *= 2000; 

  cout << fixed << setprecision(8) << cost << "\n";


  return 0;
}
