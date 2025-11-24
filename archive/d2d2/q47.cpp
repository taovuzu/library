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

void solve() {
  int aa, bb, m, vx, vy, vz;
  cin >> aa >> bb >> m >> vx >> vy >> vz;
  double time = m * -1.0 / vy;

  double xx = time * abs(vx) - aa / 2.0;
  int lx = xx / aa; 
  double x = xx - (lx * aa);
  if (xx < 0) {
    x = aa / 2.0 + time * vx;
  }
  else {
    if (vx < 0) {
      if (lx & 1) x = aa - x;
    }
    else {
      if ((lx & 1) == 0) x = aa - x;
    }
  }

  int lz = (time * vz) / bb;
  double z = (time * vz) - (lz * bb);
  if (lz & 1) z = bb - z;
  
  cout << setprecision(9) << fixed << x << " " << z;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
