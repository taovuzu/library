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

int n;
long double mat[205][205];


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 0;
  while (cin >> n && n != 0) {
    tt++;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x = a[i][0] - a[j][0], y = a[i][1] - a[j][1];
        mat[i][j] = sqrtl(x * x + y * y);
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
        }
      }
    }

    cout << fixed << setprecision(3);
    cout << "Scenario #" << tt << "\n";
    cout << "Frog Distance = " << mat[0][1] << "\n\n";
  }
  
  return 0;
}
