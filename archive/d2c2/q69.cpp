/* practice with Dukkha */
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

bool isValid(int i, int j) {
  if(i < 0 || j < 0 || i > 3 || j > 2 || (i == 3 && j == 1) || (i == 3 && j == 2)) return false;
  return true;
}

int dp[35][5][5];

int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, -1, 1, 0};

// int rec(int level, int i, int j) {
//   if(level == 0) return 1;

//   if(dp[level][i][j] != -1) return dp[level][i][j];
//   int ans = 0;
//   for(int k = 0; k < 4; k++){
//     if(isValid(i + dirx[k], j + diry[k])) {
//       ans += rec(level - 1, i + dirx[k], j + diry[k]);
//     }
//   }

//   return dp[level][i][j] = ans;
// }

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  // int ans = 0;

  // memset(dp, -1, sizeof(dp));
  // for(int i = 0; i <= 4; i++){
  //   for(int j = 0; j <= 3; j++){
  //     if(isValid(i, j)) {
  //       ans += rec(n - 1, i, j);
  //     }
  //   }
  // }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (isValid(i, j)) {
        dp[1][i][j] = 1;
      }
      else dp[1][i][j] = 0;
    }
  }

  for(int level = 2; level <= n; level++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        if (isValid(i, j)) {
            for(int k = 0; k < 4; k++){
              if(isValid(i + dirx[k], j + diry[k])) {
                dp[level][i][j] += dp[level - 1][i + dirx[k]][j + diry[k]];
              }
            }
        }
        else dp[level][i][j] = 0;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      ans += dp[n][i][j];
    }
  }

  cout << ans << "\n";

  return 0;
}
