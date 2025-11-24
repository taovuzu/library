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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0, t = n * m;
  for (int mask = 0; mask < (1 << t); mask++) {
    int res = 0;
    for (int j = 0; j < m; j++) {
      int temp = 0;
      for (int i = 0; i < n; i++) {
        if ((mask & (1 << (i * m + j))) == 0) { // horizontal
          res += temp;
          temp = 0;
        }
        else { // vertical
          temp = temp * 10 + (a[i][j] - '0');
        }
      }
      res += temp;
    }

    for (int i = 0; i < n; i++) {
      int temp = 0;
      for (int j = 0; j < m; j++) {
        if ((mask & (1 << (i * m + j))) == 0) { // horizontal
          temp = temp * 10 + (a[i][j] - '0');
        }
        else { // vertical
          res += temp;
          temp = 0;
        }
      }
      res += temp;
    }
    ans = max(ans, res);
  }

  cout << ans << "\n";
  

  return 0;
}
