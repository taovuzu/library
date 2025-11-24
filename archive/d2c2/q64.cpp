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

int n;
string s;

class state{
  public:
  int val;
  string s;

  state() : val(0), s("") {}
  state(int _val, string _s) : val(_val), s(_s){}

  bool operator>(const state &x) const {
    if (val != x.val) {
        return val > x.val;
    }
    return s < x.s;
  }
};

state dp[1005][1005];


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(cin >> s){
    n = s.size();

    for(int j = 0; j < n; j++) dp[j][j] = {1, string(1, s[j])};

    for (int cl = 2; cl <= n; cl++) {
      for (int i = 0; i <= n - cl; i++) {
        int j = i + cl - 1;
        if (s[i] == s[j]) {
          if (cl == 2) {
            dp[i][j] = {2, s.substr(i, 2)};
          }
          else {
            dp[i][j] = {dp[i + 1][j - 1].val + 2, s[i] + dp[i + 1][j - 1].s + s[j]};
          }
        }
        else {
         if (dp[i + 1][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i + 1][j];
         }
         else {
          dp[i][j] = dp[i][j - 1];
         }
        }
      }
    }
    cout << dp[0][n - 1].s << "\n";
  }

  return 0;
}