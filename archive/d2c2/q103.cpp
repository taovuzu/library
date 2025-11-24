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

const double EPS = 1e-9;

typedef complex<long double> Point;

long double dotProduct(Point a, Point b) {
  return (conj(a) * b).real();
}

long double mag(Point a) {
  return a.real() * a.real() + a.imag() * a.imag();
}

long double mag2(Point a) {
  return hypot(a.real(), a.imag());
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  long double x, y;
  while (cin >> x >> y) {
    Point c(x, y), ans;
    long double mini = 1e18;

    int n;
    cin >> n;
    vector<Point> a(n + 1);

    for (int i = 0; i <= n; i++) {
      cin >> x >> y;
      a[i] = Point(x, y);
    }

    for (int i = 1; i <= n; i++) {
      Point v = a[i] - a[i - 1];
      Point w = c - a[i - 1];
      long double t = dotProduct(v, w) / mag(v);
      long double dis;
      if (t >= 0 && t <= 1) {
        Point temp = a[i - 1] + t * (a[i] - a[i - 1]);
        dis = mag2(c - temp);
        if (dis < mini) {
          ans = temp;
          mini = dis;
        }
      }
      else {
        if (mag2(c - a[i]) < mini) {
          ans = a[i];
          mini = mag2(c - a[i]);
        }
        if (mag2(c - a[i - 1]) < mini) {
          ans = a[i - 1];
          mini = mag2(c - a[i - 1]);
        }
      }
    }

    cout << fixed << setprecision(4) << ans.real() << "\n"  << ans.imag() << "\n";
  }

  return 0;
}
