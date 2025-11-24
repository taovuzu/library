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

typedef complex<double> Point;

// Cross product defined via complex numbers.
// It computes the z-component of the 3D cross product.
double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

double getLength(Point a) {
  return hypot(a.real(), a.imag());
}

bool doSegmentsIntersect(Point a, Point b, Point c, Point d, Point &intersection) {
    double d1 = crossProduct(a - b, d - c);
    double d2 = crossProduct(a - c, d - c);
    double d3 = crossProduct(a - b, a - c);

    if (fabs(d1) < EPS)
        return false;  // Lines are parallel or identical

    double t1 = d2 / d1;
    double t2 = d3 / d1;

    intersection = a + (b - a) * t1;

    // Check if the intersection lies on both segments.
    return (t1 >= -EPS && t1 <= 1 + EPS && t2 >= -EPS && t2 <= 1 + EPS);
}


double findCircle(Point p0, Point p1, Point p2){
  Point mid1 = (p0 + p1) * 0.5;
  Point mid2 = (p2 + p1) * 0.5;

  Point v1(-(p1 - p0).imag(), (p1 - p0).real());
  Point v2(-(p2 - p1).imag(), (p2 - p1).real());


  Point end1 = mid1 + v1;
  Point end2 = mid2 + v2;

  Point center;
  doSegmentsIntersect(mid1, end1, mid2, end2, center);

  double radius = getLength(center - p0);
  double ans = 2 * (3.141592653589793) * radius;
  return ans;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  double x, y;

  while(cin >> x >> y){
    Point p0(x, y);

    cin >> x >> y;
    Point p1(x, y);

    cin >> x >> y;
    Point p2(x, y);

    double ans = findCircle(p0, p1, p2);

    cout << fixed << setprecision(2) << ans << "\n";

  }

  return 0;
}
