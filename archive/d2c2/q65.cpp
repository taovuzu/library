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

const long double EPS = 1e-9;
typedef complex<long double> Point;

int cmp(long double a, long double b) {
    if (fabsl(a - b) < EPS) return 0;
    return (a < b ? -1 : 1);
}

long double getLength(Point a) {
    return hypot(a.real(), a.imag());
}

bool intersectCircle(Point c1, long double r1, Point c2, long double r2) {
    long double d = getLength(c1 - c2);
    return cmp(fabsl(r1 - r2), d) < 0 && cmp(d, r1 + r2) < 0;
}

bool isPointInside(Point c, long double r, Point p) {
    return cmp(getLength(c - p), r) <= 0;
}

bool isCircleBetween(Point innerC, long double innerR, long double outerR,
                     Point testC, long double testR) {
    long double d = getLength(innerC - testC);
    return cmp(d - testR, innerR) >= 0 && cmp(d + testR, outerR) <= 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long double x1, y1, r1, R1, x2, y2, r2, R2;
    cin >> x1 >> y1 >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;

    Point c1(x1, y1), c2(x2, y2);
    int ans = 0;

    // Intersection tests (as in your original code)
    if (!intersectCircle(c1, r1, c2, r2) && !intersectCircle(c1, r1, c2, R2)) {
        pr('a');
        ans++;
    }
    if (!intersectCircle(c1, R1, c2, r2) && !intersectCircle(c1, R1, c2, R2)) {
        pr('b');
        ans++;
    }
    if (!intersectCircle(c2, r2, c1, r1) && !intersectCircle(c2, r2, c1, R1)) {
        pr('c');
        ans++;
    }
    if (!intersectCircle(c2, R2, c1, r1) && !intersectCircle(c2, R2, c1, R1)) {
        pr('d');
        ans++;
    }

    if (isCircleBetween(c1, r1, R1, c2, r2)) {
        pr('e');
        ans--;
    }
    if (isCircleBetween(c1, r1, R1, c2, R2)) {
        pr('f');
        ans--;
    }
    if (isCircleBetween(c2, r2, R2, c1, r1)) {
        pr('g');
        ans--;
    }
    if (isCircleBetween(c2, r2, R2, c1, R1)) {
        pr('h');
        ans--;
    }

    ans = max(0LL, ans);
    cout << ans;
    return 0;
}
