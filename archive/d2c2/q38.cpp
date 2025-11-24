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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  int ans = n;
  while(!(ans & 1)){
    int cand = ans / 2;
    bool flag = true;
    for(int i = 0; i < cand; i++){
      for(int j = 0; j < m; j++){
        if(a[i][j] != a[ans - i - 1][j]){
          flag = false;
          break;
        }
      }
      if(!flag) break;
    }
    if(flag){
      ans = cand;
    }
    else break;
  }
  cout << ans << "\n";

  return 0;
}
