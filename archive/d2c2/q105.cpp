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
  for (int cc = 1; cc <= tt; cc++) {
    cout << "Case " << cc << ":\n";
    int n, y;
    cin >> n >> y;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    for (int i = 0; i < y; i++) {
      int x_, y_;
      cin >> x_ >> y_;
      bool flag = false;
      for (int j = 0; j < n; j++) {
        int x1_ = a[j][0], y1_ = a[j][1], r = a[j][2];
        int dis = (x1_ - x_) * (x1_ - x_) + (y1_ - y_) * (y1_ - y_) - r * r;
        if (dis <= 0) {
          flag = true;
          break;
        }
      }

      cout << (flag ? "Yes" : "No") << "\n";
    }
  }

  return 0;
}
