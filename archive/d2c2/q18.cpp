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

int C[25][25];

void nck() {
  for (int i = 0; i <= 20; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

int solve(string s){
  int k = 3;
  int count = 0;
  for(int i = 0; i < s.size(); i++){
    int x = s.size() - i;
    if(s[i] == '0') continue;
    for(int j = 0; j <= k; j++){
      count += C[x - 1][j] * pow(9, j);
    }
    k--;
    if(k == -1 ) return count;
    int temp = 0;
    for(int j = 0; j <= k; j++){
      temp += C[x - 1][j] * pow(9, j);
    }
    count += (s[i] - '1') * temp;
  }
  return count;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  cin >> tt;
  nck();

  while (tt--) {
    string  l;
    int r;
    cin >> l >> r;
    int count = solve(to_string(r + 1));
    int count1 = solve(l);
    cout << (count - count1) << "\n";
  }

  return 0;
}
