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
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<array<int, 2>> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i][0] >> b[i][1];
    }

    for (int i = n - 1; i > 0; i--) {
      if (a[i] != -1) {
        if (a[i] == 0) {
          b[i - 1][0] = max(b[i][0], b[i - 1][0]);
          b[i - 1][1] = min(b[i][1], b[i - 1][1]);
        }
        else {
          b[i - 1][0] = max(b[i][0] - 1, b[i - 1][0]);
          b[i - 1][1] = min(b[i][1] - 1, b[i - 1][1]);
        }

      }
      else {
        b[i - 1][0] = max(b[i][0] - 1, b[i - 1][0]);
        b[i - 1][1] = min(b[i][1], b[i - 1][1]);
      }
    }

    bool flag = true;
    int curr = 0;

    // pr(b);
    for (int i = 0; i < n; i++) {
      if (b[i][0] > b[i][1]) {
        flag = false;
        break;
      }
      if (a[i] == 0) {
        if (curr > b[i][1] || b[i][0] > curr ) {
          flag = false;
          break;
        }
      }
      if (a[i] == 1) {
        curr++;
        if (curr > b[i][1] || b[i][0] > curr ) {
          flag = false;
          break;
        }
      }
      else {
        if (!(b[i][0] <= curr && curr <= b[i][1])) {
          curr++;
          a[i] = 1;
        }
        else a[i] = 0;
        if (curr > b[i][1] || b[i][0] > curr ) {
          flag = false;
          break;
        }
      }
    }

    if (!flag) {
      cout << -1 << "\n";
    }
    else {
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    }
  }

  return 0;
}
