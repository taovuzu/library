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

  int tt=1;  cin>>tt;
  while (tt--) {
    double p, q;
    cin >> p >> q;
    double area = p * q;
    if (p >= 4 * q) area += 0.5 * q * (p + p - 4 * q);
    else area += p * p / 8;
    double ans = p == 0.0 ? 0.5 : 1.0;
    if (p == 0.0 && q == 0.0) ans = 1.0;
    if (p * q != 0.0) ans = area / (p * q * 2);
    cout << fixed << setprecision(8) << ans << "\n";
  }

  return 0;
}
