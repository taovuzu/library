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

  int n, d;
  while(cin >> n >> d && (n != 0 || d != 0)){

    int ans = 1;

    vector<int> a(105);
    for(int j = 2; j <= n; j++){

      int i = 2, cnt = 0;
      int x = j;

      while(x > 1){
        cnt = 0;
        while(x % i == 0){
          x /= i;
          if(d % i != 0) cnt++;
          else {
            d /= i;
          }
        }
        a[i] += cnt;
        i++;
      }
    }

    for(int i = 2; i <= 100; i++){
      ans *= (a[i] + 1);
    }

    if(d != 1 && d != -1) ans = 0;

    cout << ans << "\n";

  }

  return 0;
}
