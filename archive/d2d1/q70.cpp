// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

typedef complex<int> point;

int solve(int x, int y, vector<array<point, 2>> &a) {
  for (int i = 0; i < a.size(); i++) {
    int  x1 = a[i][0].real(), y1 = a[i][0].imag(), x2 = a[i][1].real(), y2 = a[i][1].imag();
    if ((x1 < x && x < x2) || (x2 < x && x < x1)) {
      double slope = ((y2 - y1) * 1.0) / (x2 - x1);
      double temp = slope * (x - x1) + y1 - y;
      if (temp < 0) {
        if (y1 < y2) return solve(x1, y1, a);
        else return solve(x2, y2, a);
      }
    }
  }
  return x;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, m, x, y, x1, y1;
    cin >> n;
    vector<array<point, 2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> x1 >> y1;
      a[i][0] = point(x, y);
      a[i][1] = point(x1, y1);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      cout << solve(x, y, a) << "\n";
    }
    if (tt) cout << "\n";
  }

  return 0;
}
