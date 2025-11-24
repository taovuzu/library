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

int n, h;
vector<int> f(30), d(30), t(30);
int dp[30][350];
int backptr[30][350];

int fishes(int i, int k) {
  int ans = 0;
  int temp = f[i];
  while(k > 0 && temp > 0){
    ans += temp;
    temp -= d[i];
    k--;
  }
  return ans;
}

int rec(int i, int j) { // i -> lake, j -> minutes left
  j -= t[i];
  if(i >= n || j <= 0) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int ans = 0;
  for(int k = j; k >= 0; k--){
    int temp = fishes(i, k);
    int x = rec(i + 1, j - k);
    if (ans < temp + x) {
      ans = temp + x;
      backptr[i][j] = k;
    }
  }

  return dp[i][j] = ans;
}

void printer(int i, int j) {
  j -= t[i];
  if(i >= n ){
    cout << "\n";
    return;
  }
  if(j <= 0){
    if(i != 0) cout << ", ";
    cout << "0";
    return printer(i + 1, j);
  }

  if (i > 0) cout << ", ";
  cout << backptr[i][j] * 5;  
  printer(i + 1, j - backptr[i][j]);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int cnt = 0;
  while (true) {
    cin >> n;
    if(n == 0) break;
    cin >> h;
    h *= 12;

    for(int i = 0; i < n; i++){
      cin >> f[i];
    }
    for(int i = 0; i < n; i++){
      cin >> d[i];
    }
    t[0] = 0;
    for(int i = 1; i < n; i++){
      cin >> t[i];
    }

    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= h; j++){
        dp[i][j] = -1;
        backptr[i][j] = 0;
      }
    }

    int ans = rec(0, h);

    if(cnt) cout << "\n";
    printer(0, h);
    cout << "Number of fish expected: " << ans << "\n";
    cnt++;
  }

  return 0;
}
