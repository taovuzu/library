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

int n, k;
vector<int> a(205), b(205);
vector<vector<array<int, 2>>> d(205, vector<array<int, 2>>(35));

int sum(int i, int j) { return b[j] - b[i - 1]; }

int cost(int i, int j, int &c) {
  c = (i + j) / 2;
  return a[c] * (2 * c - i - j) - sum(i, c - 1) + sum(c + 1, j);
}

// i -> depot no., j ->first restaurant of last range
// d[i][j] = {location of i depot, first restaurant of last range}
void printer(int i, int j){  
  if(i == 0 && j == 0) return;
  printer(i - 1, d[j][i][1] - 1);
  if(d[j][i][1] == j){
    cout << "Depot " << i << " at restaurant " << d[j][i][0] << " serves restaurant " << j << "\n";
  }
  else {
    cout << "Depot " << i << " at restaurant " << d[j][i][0] << " serves restaurants " << d[j][i][1] << " to " << j << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int cnt = 0;
  while (cin >> n >> k && (n != 0 && k != 0)) {
    cnt++;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    b[0] = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = b[i - 1] + a[i];
    }

    vector<vector<int>> dp(n + 5, vector<int>(n + 5, (1e18)));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= min(k, i); j++){
        for(int l = j; l <= i; l++){
          int c, val = dp[l - 1][j - 1] + cost(l, i, c);
          if(val < dp[i][j]) {
            dp[i][j] = val;
            d[i][j] = {c, l};
          }
        }
      } 
    }
    
    cout << "Chain " << cnt << "\n";
    printer(k, n);
    cout << "Total distance sum = " << dp[n][k] << "\n\n";
  }

  return 0;
}
