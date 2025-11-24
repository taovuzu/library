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


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin.ignore();
    int n;
    cin >> n;

    vector<array<Point, 2>> a(n);
    for(int i = 0; i < n; i++){
      double x, y;
      cin >> x >> y;
      a[i][0] = Point(x, y);

      cin >> x >> y;
      a[i][1] = Point(x, y);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        Point temp;
        if( doSegmentsIntersect(a[i][0], a[i][1], a[j][0], a[j][1], temp)) ans++;
      }
    }

    ans *= 2;
    ans += n;
    cout << ans << "\n";
    if(tt) cout << "\n";
  }

  return 0;
}
