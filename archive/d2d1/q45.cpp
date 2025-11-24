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

  int n, m;
  cin >> n >> m;
  vector<bool> a(n, true), b(n, true);
  a[0] = false, b[0] = false, a[n - 1] = false, b[n - 1] = false;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x - 1] = false;
    b[y - 1] = false;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] && b[i]) {
      if ((n & 1) && (i == n / 2)) ans++;
      else ans += 2;
    }
    else if (a[i] || b[i]) ans++;
  }

  cout << ans << "\n";

  return 0;
}
