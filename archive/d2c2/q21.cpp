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

  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for(int j = 0; j < n; j++){
    vector<int> b = a;
    b.insert(b.begin() + j, x);
    while(true){
      bool flag = false;
      int m = b.size();
      for(int i = 0; i + 2 < b.size(); i++){
        if(b[i] == b[i + 1] && b[i + 1] == b[i + 2]){
          flag = true;
          int temp = i + 3;
          while(temp < m && b[temp] == b[i] ){
          temp++;
          }
          b.erase(b.begin() + i, b.begin() + temp);
        }
      }
      int temp1 = a.size() - b.size();
      ans = max(ans, temp1);
      if(!flag) break;
    }
  }


  cout << ans << "\n";

  return 0;
}