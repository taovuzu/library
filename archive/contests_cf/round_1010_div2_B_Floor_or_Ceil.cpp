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
    int x, n, m;
    cin >> x >> n >> m;
    int temp = x, temp1 = x;
    int temp2 = n, temp3 = m;
    while (n > 0 && temp > 0){
      n--;
      temp /= 2;
    }
    while (m > 0 && temp > 1){
      m--;
      temp = (temp + 1) / 2;
    }
    n = temp2, m = temp3;
    while (m > 0 && temp1 > 1){
      m--;
      temp1 = (temp1 + 1) / 2;
    }
    while (n > 0 && temp1 > 0){
      n--;
      temp1 /= 2;
    }

    cout << temp1 << " " << temp << "\n";
  }

  return 0;
}