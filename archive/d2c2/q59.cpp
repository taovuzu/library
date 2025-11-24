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

const long double PI = 3.141592653589793238462643383279502884L;
const long double EPS = 1e-12;  

typedef complex<long double> Point;

// Compute the angle of a complex number
long double getAngle(Point a) {
    return atan2l(a.imag(), a.real());
}

// Compute vector from point A to B
Point getVector(Point a, Point b) {
    return b - a;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long double deg = 180.0L / PI;
    vector<long double> a(n);
    for (int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;
        a[i] = getAngle(Point(x, y)) * deg;
    }

    sort(a.begin(), a.end());
    long double ans = 0.0L;
    for (int i = 1; i < n; i++) {
      ans = max(ans, a[i] - a[i - 1]);
    }

    ans = max(ans, 360.0L - (a[n - 1] - a[0]));

    if(ans != 0.0L) ans = 360.0L - ans;

    cout << fixed << setprecision(8) << ans << "\n";

    return 0;
}
