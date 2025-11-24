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

int l, r, x;

void solve() {
  if (x) {
    cout << (r + 2) / 4 - (l + 1) / 4 << "\n";
  }
  else {
    if (l & 1) {
      cout << ((l >> 1) + 1) << " " << (l >> 1) << "\n";
    }
    else if ((l & 3) == 0) {
      cout << ((l >> 2) + 1) << " " << ((l >> 2) - 1) << "\n";
    }
    else {
      cout << "Bachelor Number." << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    ss >> l;
    if (ss >> r) x = 1;
    else x = 0;
    solve();
  }

  return 0;
}
