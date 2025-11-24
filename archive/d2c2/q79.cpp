/* Embrace boredom and hard work; only through relentless discipline does mastery unlock a universe of true pleasure. */
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

int digitSum(int x) {
  int sum = 0;
  while(x) {
    sum += (x % 10);
    x /= 10;
  }
  return sum;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  int root = sqrtl(n);
  int ans = -1;

  pr(root);
  for(int i = max(0LL, root - 100); i <= root + 100; i++) {
    if(i * (i + digitSum(i)) == n) {
      ans = i;
      break;
    }
  }

  cout << ans ;

  return 0;
}
