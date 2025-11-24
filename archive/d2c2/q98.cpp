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

vector<array<int, 4>> a(4);

void rotate(int i) {
  int x = a[i][0], y = a[i][1], h1 = a[i][2], h2 = a[i][3];
  a[i][0] = h1 - (y - h2);
  a[i][1] = h2 + (x - h1);
}

bool isSquare() {
    auto dist2 = [](int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    };

    vector<int> dists;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            dists.push_back(dist2(a[i][0], a[i][1], a[j][0], a[j][1]));

    sort(dists.begin(), dists.end());

    return dists[0] > 0 &&
           dists[0] == dists[1] &&
           dists[1] == dists[2] &&
           dists[2] == dists[3] &&
           dists[4] == dists[5] &&
           dists[4] > dists[0];
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> a[i][j];
      }
    }

    int ans = LLONG_MAX;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          for (int l = 0; l < 4; l++) {
            if (isSquare()) {
              ans = min(ans, i + j + k + l);
            }
            rotate(3);
          }
          rotate(2);
        }
        rotate(1);
      }
      rotate(0);
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";

  }

  return 0;
}
