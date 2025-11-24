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

int x1, y1, x2, y2, x3, y3;

bool check(int p, int p1, int p2) {
  return (p2 <= p1 && p2 <= p) || (p2 >= p1 && p2 >= p);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
    cout << 1 << "\n";
  }
  else if (x1 == x2 || x2 == x3 || y1 == y2 || y2 == y3 || x1 == x3 || y1 == y3) {
    if (x1 == x2 ) {
      if (check(y1, y2, y3)) {
        cout << 2 << "\n";
      }
      else cout << 3 << "\n";
    }
    else if (x2 == x3) {
      if (check(y2, y3, y1)) {
        cout << 2 << "\n";
      }
      else cout << 3 << "\n";
    }
    else if (x1 == x3) {
      if (check(y1, y3, y2)) {
        cout << 2 << "\n";
      }
      else cout << 3 << "\n";
    }
    else {
      swap(x1, y1), swap(x2, y2), swap(x3, y3);
      if (x1 == x2 ) {
        if (check(y1, y2, y3)) {
          cout << 2 << "\n";
        }
        else cout << 3 << "\n";
      }
      else if (x2 == x3) {
        if (check(y2, y3, y1)) {
          cout << 2 << "\n";
        }
        else cout << 3 << "\n";
      }
      else if (x1 == x3) {
        if (check(y1, y3, y2)) {
          cout << 2 << "\n";
        }
        else cout << 3 << "\n";
      }
    } 
  }
  else cout << 3 << "\n";

  return 0;
}
