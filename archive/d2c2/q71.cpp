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

void rot(array<int, 6> &a, int i){
  reverse(a.begin(), a.begin() + i + 1);
  reverse(a.begin() + i + 1, a.end());
  reverse(a.begin(), a.end());
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  set<array<int, 6>> xt;
  array<int, 6> a;

  bool ans = false;
  for(int i = 0; i < n; i++) {
    vector<array<int, 6>> b;
    for(int j = 0; j < 6; j++) {
      cin >> a[j];
    }

    if(!ans) {
      for(int j = 0; j < 6; j++) {
        rot(a, 0);
        array<int, 6> temp = a;
        if(xt.find(a) != xt.end()) ans = true;
        reverse(temp.begin(), temp.end());
        if(xt.find(temp) != xt.end()) ans = true;
      }
      xt.insert(a);
    }
  }

  cout << (ans ? "Twin snowflakes found." : "No two snowflakes are alike.") << "\n";

  return 0;
}
