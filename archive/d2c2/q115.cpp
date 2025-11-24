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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const double EPS = 1e-9;
typedef complex<double> point;

struct circle {
  point c;
  double r;
};

circle getCircleFromTwoPoints(point a, point b) {
  point c = (a + b) / 2.0;
  double r = abs(b - a) / 2.0;
  return {c, r};
}

circle getCircleFromThreePoints(point A, point B, point C) {
  double a = A.real(), b = A.imag();
  double c = B.real(), d = B.imag();
  double e = C.real(), f = C.imag();

  double A1 = c - a;
  double B1 = d - b;
  double C1 = (A1 * (a + c) + B1 * (b + d)) / 2.0;

  double A2 = e - a;
  double B2 = f - b;
  double C2 = (A2 * (a + e) + B2 * (b + f)) / 2.0;

  double det = A1 * B2 - A2 * B1;

  if (abs(det) < EPS) {
    return {{0, 0}, 1e18};
  }

  double cx = (C1 * B2 - C2 * B1) / det;
  double cy = (A1 * C2 - A2 * C1) / det;
  point center = {cx, cy};
  double radius = abs(center - A);
  return {center, radius};
}

circle welzl(const vector<point> &P, int n, vector<point> R = {}) {
    if (n == 0 || R.size() == 3) {
        if (R.empty())      return {{0,0}, 0};
        if (R.size() == 1)  return {R[0], 0};
        if (R.size() == 2)  return getCircleFromTwoPoints(R[0], R[1]);
        return getCircleFromThreePoints(R[0], R[1], R[2]);
    }

    point p = P[n-1];
    circle d = welzl(P, n-1, R);
    if (abs(p - d.c) <= d.r + EPS) {
        return d;
    }
    R.push_back(p);
    return welzl(P, n-1, R);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<point> a(n);
    for (int i = 0; i < n; i++) {
      double x_, y_;
      cin >> x_ >> y_;
      a[i] = point(x_, y_);
    }

    shuffle(a.begin(), a.end(), rng);
    circle c = welzl(a, n);

    cout << fixed << setprecision(2) << c.r << "\n"
     << c.c.real() << " " << c.c.imag() << "\n";
  }

  return 0;
}
