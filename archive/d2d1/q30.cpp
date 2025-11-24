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

  int n, m, x, y, z, ans = LLONG_MAX;
  cin >> n >> m;

  vector<long long> d(n+1), e(m+1), b(n+1), c(m+1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> z;
       d[i] += z;
       e[j] += z;
    }
  }

  for (int i = 0; i <= n; i++) {
    b[i] = 0;
    for (int j = 1; j <= n; j++) {
      b[i] += d[j] * (4 * i - 4 * j + 2) * (4 * i - 4 * j + 2);
    }
  }

  for (int i = 0; i <= m; i++) {
    c[i] = 0;
    for (int j = 1; j <= m; j++) {
      c[i] += e[j] * (4 * i - 4 * j + 2) * (4 * i - 4 * j + 2);
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if ( ans > (b[i] + c[j])) {
        ans = b[i] + c[j];
        x = i, y = j;
      }
    }
  }

  cout << ans << "\n" << x << " " << y;
  return 0;
}
