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

const double PI = acos(-1.0);
const double EPS = 1e-12;

struct circle{
  double x;
  double y;
  double r;
  double area;
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<circle> a(n);
  for (int i = 0; i < n; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    a[i] = circle(x, y, r, PI * r * r);
  }

  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if ((a[j].x - a[j].r <= a[i].x && a[i].x <= a[j].x + a[j].r) && (a[j].y - a[j].r <= a[i].y && a[i].y <= a[j].y + a[j].r) && (a[i].r <= a[j].r)) {
        b[i]++;
      }
    }
  }

  double ans = 0;
  for (int i = 0; i < n; i++) {
    int k = b[i] / 2;
    if (k & 1) ans -= a[i].area;
    else ans += a[i].area;
  }

  cout << fixed << setprecision(12) << ans << "\n";

  return 0;
}
