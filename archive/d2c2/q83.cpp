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

  int n, _x1, y1_, _x2, _y2;
  cin >> n >> _x1 >> y1_ >> _x2 >> _y2;

  vector<array<int, 2>> a(n + 1);
  for (int i = 0; i < n; i++) {
    int _x, _y;
    cin >> _x >> _y;
    a[i][0] = (_x - _x1) * (_x - _x1) + (_y - y1_) * (_y - y1_);
    a[i][1] = (_x - _x2) * (_x - _x2) + (_y - _y2) * (_y - _y2);
  }

  int ans = LLONG_MAX;

  for (int i = 0; i <= n; i++) {
    int temp = a[i][0], temp1 = 0;
    for(int j = 0; j <= n; j++) {
      if(temp < a[j][0] && temp1 < a[j][1]) temp1 = a[j][1];
    }
    ans = min(ans, temp + temp1);
  }

  cout << ans << "\n";
  return 0;
}