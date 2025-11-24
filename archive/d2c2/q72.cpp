/* practice with Dukkha */
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

const long double EPS = 1e-12;
const long double PI = acos(-1.0);
const long double Deg = 180 / PI;

typedef complex<double> Point;

Point getVector(Point p0, Point p1) {
  return p1 - p0;
}

double getAngle(Point a) {
  long double angle = atan2(a.imag(), a.real()) * Deg ;
  if (angle < 0) angle += 360;
  return angle;
}

int comp(long double x, long double y) {
  return abs(x - y) <= EPS ? 0 : (x < y ? 1 : -1);
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    long double x1, y1, u1, v1, x2, y2, u2, v2;
    cin >> x1 >> y1 >> u1 >> v1 >> x2 >> y2 >> u2 >> v2;

    Point hero = getVector(Point(x1, y1), Point(u1, v1)), heroine = getVector(Point(x2, y2), Point(u2, v2)), 
          slope1 = getVector(Point(x1, y1), Point(x2, y2)), slope2 = getVector(Point(x2, y2), Point(x1, y1));
    long double m1 = getAngle(hero), m2 = getAngle(heroine), m3 = getAngle(slope1), m4 = getAngle(slope2);

    // pr(hero, heroine, slope1, slope2);
    // pr(m1, m2, m3, m4);

    long double heroR = min({abs(m3 - m1), abs(m3 - m1 + 360), abs(m1 - m3 + 360)});
    long double heroineR = min({abs(m4 - m2), abs(m4 - m2 + 360), abs(m2 - m4 + 360)});

    // pr(heroR, heroineR);

    if (comp(heroR, heroineR) == 0) {
      cout << 0 << "\n";
    }
    else if(comp(heroR, heroineR) == 1) {
      cout << "Hero" << "\n";
    }
    else {
      cout << "Heroine" << "\n";
    }
  }

  return 0;
}
