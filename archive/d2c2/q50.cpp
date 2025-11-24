#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;

  int temp = n * m + (n == 1 ? 0 : (n - 2) * m); // we are taking one period of => {1 to n to 2 }
  int alpha = k / temp;

  k %= temp;

  vector<vector<int>> a(105, vector<int>(105));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] += alpha;
      if(i != 1 && i != n) a[i][j] += alpha;
    }
  }

  for(int i = 1; i <= n && k > 0; i++){
    for(int j = 1; j <= m && k > 0; j++){
      a[i][j]++;
      k--;
    }
  }

  for(int i = n - 1; k > 0; i--){
    for(int j = 1; j <= m && k > 0; j++){
      a[i][j]++;
      k--;
    }
  }

  int maxi = max({a[1][1], a[2][1], a[n - 1][1]}), mini = a[n][m];

  cout << maxi << " " << mini << " " << a[x][y] << "\n";

  return 0;
}
