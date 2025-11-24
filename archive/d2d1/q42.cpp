// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int x, y, q, l, t, m;
  cin >> x >> y >> q;

  while (q--) {
    cin >> l >> t >> m;
    int lo = 1, hi = 1e7, n = -1, z = x + (l - 1) * y;

    if (z > t) {
      cout << -1 << "\n";
      continue;
    }

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      int last = z + (mid - 1) * y;
      int sum = ((z + last) * mid) / 2;
      if (sum <= m * t && last <= t) {
        n = mid;
        lo = mid + 1;
      }
      else {
        hi = mid - 1;
      }
    }

    cout << l + n - 1 << "\n";
  }


  return 0;
}