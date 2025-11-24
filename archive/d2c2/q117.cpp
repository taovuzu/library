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

typedef complex<double> point;

double getArea(point a, point b, point c) {
  int x1 = a.real(), x2 = b.real(), x3 = c.real();
  int y1 = a.imag(), y2 = b.imag(), y3 = c.imag();

  return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

double crossProduct(point a, point b) {
  return (conj(a) * b).imag();
}

int ccw(point a, point b, point c) {
  return crossProduct(b - a, c - a);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  
  vector<point> a(n);
  for (int i = 0; i < n; i++) {
    double x_, y_;
    cin >> x_ >> y_;
    a[i] = point(x_, y_);
  }

  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double area = 0, area2 = 0;
      for (int k = 0; k < n; k++) {
        if(k == i || k == j) continue;
        double test = ccw(a[i], a[j], a[k]);
        if(test > 0) {
          area = max(getArea(a[i], a[j], a[k]), area);
        }
        else if(test < 0) {
          area2 = max(getArea(a[i], a[j], a[k]), area2);
        }
      }
      if(area == 0.0 || area2 == 0.0) continue;
      ans = max(ans , area + area2);
    }
  }

  cout << fixed << setprecision(12) << ans << "\n";

  return 0;
}
