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
  cin.ignore();
  cin.ignore();

  for (int cc = 0; cc < tt; cc++) {
    if(cc) cout << "\n";
    string s;
    vector<array<int, 2>> a;

    while (getline(cin, s)) {
      if(s.empty()) break;
       istringstream iss(s);
        int x_, y_;
        if (iss >> x_ >> y_) {
            a.push_back({x_, y_});
        }
    }
    
    int n = a.size();
    int ans = min(n, 2LL);
    for (int i = 0; i < n; i++) {
      map<pair<int, int>, int> mp;
      int local_max = 0;

      for (int j = 0; j < n; j++) {
        if (i == j) continue;

        int dx = a[j][0] - a[i][0];
        int dy = a[j][1] - a[i][1];

        int g = __gcd(dx, dy);
        dx /= g;
        dy /= g;

        if (dx < 0) {
          dx = -dx;
          dy = -dy;
        } else if (dx == 0) {
          dy = abs(dy);
        }

        mp[{dx, dy}]++;
        local_max = max(local_max, mp[{dx, dy}]);
      }

      ans = max(ans, local_max + 1); 
    }

    cout << ans << "\n";
  }

  return 0;
}
