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

class item{
  public:
    int x, y;
    char ch;

    item() {}

    void scan(int i) {
      cin >> x >> y;
      if (x < y) swap(x, y);
      ch = 'A' + i;
    }

    bool operator < (item& a) {
      if (x != a.x) return x > a.x;
      return y > a.y;
    }
};

item a[3];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < 3; i++) {
    a[i].scan(i);
  }

  sort(a, a + 3);
  int area = a[0].x * a[0].y + a[1].x * a[1].y + a[2].x * a[2].y;

  int n = 0;
  while (n * n < area) n++;
  if (n * n != area || a[0].x != n) {
    cout << -1 ;
    return 0;
  }

  if (a[1].x == n && a[2].x == n) {
    cout << n << "\n";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < a[i].y; j++) {
        for (int k = 0; k < n; k++) {
          cout << a[i].ch;
        }
        cout << "\n";
      }
    }
    return 0;
  }

  int rem = n - a[0].y;
  for (int i = 1; i < 3; i++) {
    if (a[i].y != rem)  swap(a[i].y, a[i].x);
    if (a[i].y != rem) {
      cout << "-1" ;
      return 0;
    }
  }

  cout << n << "\n";
  for (int i = 0; i < a[0].y; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[0].ch;
    }
    cout << "\n";
  }
  for (int i = 0; i < rem; i++) {
    for (int j = 0; j < n; j++) {
      if (j < a[1].x) {
        cout << a[1].ch;
      }
      else cout << a[2].ch;
    }
    cout << "\n";
  }

  return 0;
}
