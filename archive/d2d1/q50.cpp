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

const double PI = acos(-1.0);

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cout << fixed << setprecision(2);

  int a, b, s, n, m;
  while (cin >> a >> b >> s >> m >> n, a) {
    double len = hypot(1.0 * a * m, 1.0 * b * n) / s;
    double angle = atan2(1.0 * b * n, 1.0 * a * m) * 180.0 / PI;
    cout << angle << " " << len << "\n";
  }

  return 0;
}
