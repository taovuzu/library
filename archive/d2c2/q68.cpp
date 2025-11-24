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

const int mod = 1e8;

int n1, n2, k1, k2, n;
int dp[105][105][2];

int rec(int ones, int twos,int flag) {
  if(ones == 0 && twos == 0) return 1;

  if (dp[ones][twos][flag] != -1) return dp[ones][twos][flag];

  int ans = 0;
  if (flag) {
    for(int i = 1; i <= min(k2, twos); i++){
      ans += rec(ones, twos - i, 0);
    }
  }
  else {
    for(int i = 1; i <= min(k1, ones); i++){
      ans += rec(ones - i, twos, 1);
    }  
  }

  return dp[ones][twos][flag] = ans % mod;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n1 >> n2 >> k1 >> k2;

  n = n1 + n2;
 
  memset(dp, -1, sizeof(dp));
  int ans = (rec(n1, n2, 0) + rec(n1, n2, 1)) % mod;

  cout << ans;

  return 0;
}
