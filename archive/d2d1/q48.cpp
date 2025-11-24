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
  while (cin >> n >> m) {
    cin.ignore();
    vector<vector<string>> a(n, vector<string> (m));
    for (int i = 0; i < n; i++) {
      string s, s1 = "";
      int j = 0;
      getline(cin, s);
      s += ",";
      for (auto it : s) {
        if (it == ',') {
          a[i][j++] = s1;
          s1 = "";
        }
        else s1 += it;
      }
    }

    int u, v, x, y;
    bool flag = false;
    for (int k = 0; k < m; k++) {
      for (int l = k + 1; l < m; l++) {
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
          string s = a[i][k] + "," + a[i][l];
          if (mp.find(s) != mp.end()) {
            x = mp[s] + 1;
            y = i + 1;
            u = k + 1;
            v = l + 1;
            flag = true;
          }
          else mp[s] = i;
          if (flag) break;
        }
        if (flag) break;
      }
      if (flag) break;
    }

    if (flag) {
      cout << "NO" << "\n";
      cout << x << " " << y << "\n";
      cout << u << " " << v << "\n";
    }
    else {
      cout << "YES" << "\n";
    }
  }

  return 0;
}
