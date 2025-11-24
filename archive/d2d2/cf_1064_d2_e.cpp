// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

bool ask(int x, int y) {
  cout << x << " " << y << endl;
  string s;
  cin >> s;
  return s == "white";
}


void solve() {
  int x = 0, x1 = 1LL << 20, y = 0, y1 = 1LL << 20, n, z = 16;
  cin >> n;
  while (z-- && n--) {
    int midx = (x + x1) / 2;
    if (ask(midx, 0)) x1 = midx;
    else x = midx;
  }
  x = (x + x1) / 2;
  while (n-- > 0) {
    int midy = (y + y1) / 2;
    if (ask(x, midy)) y1 = midy;
    else y = midy;
  }
  cout << (x + x1) / 2 << " 0 " << x << " " << (y + y1) / 2 << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
