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

const int mod = 1e9 + 7;

int n, k, d;
int dp[105][2];

int rec(int target, int flag) {
  if(target < 0) return 0;
  if(target == 0) return flag;

  if(dp[target][flag] != -1) return dp[target][flag];

  int ans = 0;
  for(int i = 1; i <= k; i++){
    ans += rec(target - i, (i >= d || flag ));
  }

  return dp[target][flag] = ans % mod;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k >> d;

  for(int i = 0; i <= n; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
  }

  cout << rec(n, false);

  return 0;
}
