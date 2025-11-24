// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

void solve() {
  int sum, x, y, z;
  cin >> sum >> x >> y >> z;
  if (x == 0 && y == 0 && z == 0) {
    cout << "0 0 0";
    return;
  }
  cout << setprecision(12) << fixed << (1.0 * sum * x) / (x + y + z) << " " << (1.0 * sum * y) / (x + y + z) << " "  << (1.0 * sum * z) / (x + y + z);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
