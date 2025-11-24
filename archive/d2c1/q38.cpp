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

long double prob[25];
int n, r;

long double calculate(int i, int left, int special) {
  if (i >= n) {
    return (left == 0) ? 1.0 : 0.0;
  }

  long double take = 0;
  if(i==special) return calculate(i+1,left,special);
  if (left >= 1)
    take = calculate(i + 1, left - 1, special) * prob[i];

  long double notTake = calculate(i + 1, left, special) * (1 - prob[i]);

  return  take + notTake;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 0;
  while (cin >> n >> r && (n || r)) {
    tt++;
    cout << fixed << setprecision(6);

    for (int i = 0; i < n; i++) {
      cin >> prob[i];
    }

    long double total = calculate(0, r, -1);

    cout << "Case " << tt << ":" << "\n";

    for (int i = 0; i < n; i++) {
      long double partial = prob[i] * calculate(0, r - 1, i);

      if (total == 0) {
        cout << "0.000000\n";
      } else {
        cout << partial / total << "\n";
      }
    }
  }

  return 0;
}
