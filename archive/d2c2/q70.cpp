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

int a[40], b[40];
int n = 0, maxi;

int rec(int level, int left) {
  if(left < 0) return 0;
  if(left == 0) return 1;
  if(level > n) return 0;

  int ans = 0;
  for (int i = 0; i <= min(b[level], left); i++) {
    ans += rec(level + 1, left - i);
  }

  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int x;
  while(cin >> x) {
    a[n++] = x;
    for(int i = 1; i <= x; i++) {
      b[i]++;
    }
  }

  maxi = *max_element(a, a + 40);
  cout << rec(1, n);

  return 0;
}
