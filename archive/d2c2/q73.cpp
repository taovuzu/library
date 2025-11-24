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

bool alignCheck(int x0, int x1, int x2, int x3) {
  return  (x0 != x2) && (x1 != x3);
}

bool isNotAligned(int x0, int y0, int x1, int y1) {
  return alignCheck(0, 0, x0, y0) && alignCheck(x0, y0, x1, y1) && alignCheck(x1, y1, 0, 0);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b;
  cin >> a >> b;

  for (int x = 1; x < a; x++ ) {
    int y = sqrtl(a * a - x * x);
    if (x * x + y * y == a * a) {
      int gcd = __gcd(x, y);
      int x0 = -y / gcd;
      int y0 = x / gcd;
      
      int lenB = a / gcd;

      if (b % lenB == 0) {
        x0 *= (b / lenB);
        y0 *= (b / lenB);

        if(isNotAligned(x, y, x0, y0)) {
          cout << "YES" << "\n";
          cout << "0 0" << "\n";
          cout << x << " " << y << "\n";
          cout << x0 << " " << y0 << "\n";

          return 0;
        }
      }
    }
  }

  cout << "NO" << "\n";

  return 0;
}
