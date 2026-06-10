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
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    
    bool ans = true;
    for(int i = 0; i < n; i++){
      bool flag = true;
      for(int j = 0; j < m; j++){
        if(a[i][j] == '0'){
          flag = false;
          continue;
        }
        if(!flag){
          for(int k = i - 1; k >= 0; k--){
            if(a[k][j] == '0'){
              ans = false;
              break;
            }
          }
        }
      }
      if(!ans){
        break;
      }
    }

    cout << (ans ? "YES" : "NO") << "\n";
  }

  return 0;
}
