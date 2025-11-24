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
  while(cin >> n >> m){
    vector<vector<int>> a(n, vector<int> (m, 0));
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>> (m));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> a[i][j];
        if(j == m - 1){
          dp[i][j][0] = a[i][j];
          dp[i][j][1] = i;
        }
      }
    }
  
    for(int j = m - 2; j >= 0; j--){
      for(int i = 0; i < n; i++){
        dp[i][j][0] = min({dp[i][j + 1][0], dp[(i - 1 + n) % n][j + 1][0], dp[(i + 1) % n][j + 1][0]});
        if(i == 0){
          if(dp[i][j][0] == dp[i][j + 1][0]){
            dp[i][j][1] = i;
          }
          else if(dp[i][j][0] == dp[(i + 1) % n][j + 1][0]){
            dp[i][j][1] = (i + 1) % n;
          }
          else {
            dp[i][j][1] = n - 1;
          }
        }
        else if(i == n - 1){
          if(dp[i][j][0] == dp[0][j + 1][0]){
            dp[i][j][1] = 0;
          }
          else if(dp[i][j][0] == dp[i - 1][j + 1][0]){
            dp[i][j][1] = i - 1;
          }
          else {
            dp[i][j][1] = i;
          }
        }
        else {
          if(dp[i][j][0] == dp[i - 1][j + 1][0]){
            dp[i][j][1] = i - 1 ;
          }
          else if(dp[i][j][0] == dp[i][j + 1][0]){
            dp[i][j][1] = i;
          }
          else {
            dp[i][j][1] = i + 1;
          }
        }
        dp[i][j][0] += a[i][j];
      }
    }
  
    int ans = LLONG_MAX, idx = 0;
    for(int i = 0; i < n; i++){
      if(dp[i][0][0] < ans ){
        ans = dp[i][0][0];
        idx = i;
      }
    }

    int j = 0;
    while(j < m){
      cout << idx + 1<< " \n"[j == m - 1];
      idx = dp[idx][j][1];
      j++;
    }
  
    cout << ans << "\n";
  }

  return 0;
}
