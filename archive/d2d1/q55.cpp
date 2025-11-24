// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}q
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1, cc = 0;  cin >> tt;
  while (tt--) {
    int n, s1, v1, s2, v2, ans = 0, res = 0;
    cin >> n >> s1 >> v1 >> s2 >> v2;

    int lcm = (s1 * s2) / __gcd(s1, s2);
    int lcm_cnt = max(n / lcm - 1, 0LL);
    ans = lcm_cnt * max((lcm / s1) * v1, (lcm / s2) * v2);
    n -= lcm_cnt * lcm;

    if (s1 < s2) swap(s1, s2), swap(v1, v2);
    for (int i = 0; i * s1 <= n; i++) {
      res = max(res, i * v1 + ((n - i * s1) / s2 ) * v2);
    }

    cout << "Case #" << (++cc) << ": " << res + ans << "\n";
  }

  return 0;
}
